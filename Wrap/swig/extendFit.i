 // introduced because of FitCylindersAndPrisms example
%extend FitSuiteParameters {
    const FitParameter* __getitem__(std::string name) const
    {
        return (*($self))[name];
    }
    const FitParameter* __getitem__(size_t index) const
    {
        return (*($self))[index];
    }
};
