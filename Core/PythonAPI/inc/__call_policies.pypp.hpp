// This file has been generated by Py++.

// Copyright 2004-2008 Roman Yakovenko.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef call_policies_pyplusplus_hpp__
#define call_policies_pyplusplus_hpp__

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "boost/cstdint.hpp"
#include "boost/mpl/int.hpp"
#include "boost/function.hpp"
#include "boost/utility/addressof.hpp"
#include "boost/type_traits/is_same.hpp"
#include "boost/python/object/class_detail.hpp"

namespace pyplusplus{ namespace call_policies{

namespace bpl = boost::python;

namespace memory_managers{

    struct none{
        template< typename T>
        static void deallocate_array(T*){}
    };

    struct delete_{
        template< typename T>
        static void deallocate_array(T* arr){
            delete[] arr;
        }
    };

}/*memory_managers*/


namespace detail{

struct make_value_holder{

    template <class T>
    static PyObject* execute(T* p){
        if (p == 0){
            return bpl::detail::none();
        }
        else{
            bpl::object p_value( *p );
            return bpl::incref( p_value.ptr() );
        }
    }
};

template <class R>
struct return_pointee_value_requires_a_pointer_return_type
# if defined(__GNUC__) && __GNUC__ >= 3 || defined(__EDG__)
{}
# endif
;

struct make_addressof_holder{

    template <class T>
    static PyObject* execute(T* p){
        if (p == 0){
            return bpl::detail::none();
        }
        else{
            size_t addressof_p = size_t( p );
            bpl::object p_address( addressof_p );
            return bpl::incref( p_address.ptr() );
        }
    }

};

template <class R>
struct return_addressof_value_requires_a_pointer_return_type
# if defined(__GNUC__) && __GNUC__ >= 3 || defined(__EDG__)
{}
# endif
;


} //detail

struct return_pointee_value{

    template <class T>
    struct apply{

        BOOST_STATIC_CONSTANT( bool, ok = boost::is_pointer<T>::value );

        typedef typename boost::mpl::if_c<
            ok
            , bpl::to_python_indirect<T, detail::make_value_holder>
            , detail::return_pointee_value_requires_a_pointer_return_type<T>
        >::type type;

    };

};

struct return_addressof{

    template <class T>
    struct apply{

        BOOST_STATIC_CONSTANT( bool, ok = boost::is_pointer<T>::value );

        typedef typename boost::mpl::if_c<
            ok
            , bpl::to_python_indirect<T, detail::make_addressof_holder>
            , detail::return_addressof_value_requires_a_pointer_return_type<T>
        >::type type;

    };

};

template< typename CallPolicies, class T >
bpl::object make_object( T x ){
    //constructs object using CallPolicies result_converter
    typedef BOOST_DEDUCED_TYPENAME CallPolicies::result_converter:: template apply< T >::type result_converter_t;
    result_converter_t rc;
    return bpl::object( bpl::handle<>( rc( x ) ) );
}

namespace arrays{

namespace details{

template< unsigned int size, typename MemoryManager, typename CallPolicies>
struct as_tuple_impl{

    template <class U>
    inline PyObject* operator()(U const* arr) const{
        if( !arr ){
            return bpl::incref( bpl::tuple().ptr() );
        }
        bpl::list list_;
        for( unsigned int i = 0; i < size; ++i ){
            list_.append( make_object< CallPolicies>( arr[i] ) );
        }
        MemoryManager::deallocate_array( arr );
        return bpl::incref( bpl::tuple( list_ ).ptr() );
    }

    static PyTypeObject const *get_pytype(){
        return &PyTuple_Type;
    }

};

}

template< unsigned int size, typename MemoryManager, typename MakeObjectCallPolicies=bpl::default_call_policies>
struct as_tuple{
public:

    template <class T>
    struct apply{
        BOOST_STATIC_CONSTANT( bool, ok = boost::is_pointer<T>::value );
        typedef details::as_tuple_impl<size, MemoryManager, MakeObjectCallPolicies> type;
    };

};

} /*arrays*/

} /*pyplusplus*/ } /*call_policies*/


#endif//call_policies_pyplusplus_hpp__


