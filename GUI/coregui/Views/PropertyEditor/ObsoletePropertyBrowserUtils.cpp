// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/PropertyEditor/ObsoletePropertyBrowserUtils.cpp
//! @brief     Implements class ObsoletePropertyBrowserUtils
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "ObsoletePropertyBrowserUtils.h"
#include "CustomEventFilters.h"
#include "MaterialItemUtils.h"
#include <QColorDialog>
#include <QComboBox>
#include <QDoubleValidator>
#include <QFileDialog>
#include <QFocusEvent>
#include <QHBoxLayout>
#include <QIcon>
#include <QLabel>
#include <QLineEdit>
#include <QPixmap>
#include <QRgb>
#include <QToolButton>

// -----------------------------------------------------------------------------
// MaterialPropertyEdit
// -----------------------------------------------------------------------------

ObsoleteMaterialPropertyEdit::ObsoleteMaterialPropertyEdit(QWidget *parent)
    : QWidget(parent)
    , m_focusFilter(new LostFocusFilter(this))
{
    setMouseTracking(true);
    setAutoFillBackground(true);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setMargin(2);
    layout->setSpacing(0);

    m_textLabel = new QLabel;
    m_textLabel->setText(m_materialProperty.getName());

    m_pixmapLabel = new QLabel;
    m_pixmapLabel->setPixmap(m_materialProperty.getPixmap());

    QToolButton *button = new QToolButton;
    button->setSizePolicy(QSizePolicy(QSizePolicy::Fixed,
                                      QSizePolicy::Preferred));
    button->setText(QLatin1String("..."));
    layout->addWidget(m_pixmapLabel, Qt::AlignLeft);
    layout->addWidget(m_textLabel, Qt::AlignLeft);
    layout->addStretch(1);
    layout->addWidget(button);
    setFocusPolicy(Qt::StrongFocus);
    setAttribute(Qt::WA_InputMethodEnabled);
    connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));

    setLayout(layout);
}

void ObsoleteMaterialPropertyEdit::buttonClicked()
{
    // temporarily installing filter to prevent loss of focus caused by too  insistent dialog
    installEventFilter(m_focusFilter);
    ExternalProperty mat = MaterialItemUtils::selectMaterialProperty(m_materialProperty);
    removeEventFilter(m_focusFilter);

    if(mat.isDefined() ) {
        setMaterialProperty(mat);
        emit materialPropertyChanged(m_materialProperty);
    }
}


void ObsoleteMaterialPropertyEdit::setMaterialProperty(
        const ExternalProperty &materialProperty)
{
    m_materialProperty = materialProperty;
    m_textLabel->setText(m_materialProperty.getName());
    m_pixmapLabel->setPixmap(m_materialProperty.getPixmap());
}


// -----------------------------------------------------------------------------
// GroupPropertyEdit
// -----------------------------------------------------------------------------
ObsoleteGroupPropertyEdit::ObsoleteGroupPropertyEdit(QWidget *parent)
    : QWidget(parent)
    , m_box(new QComboBox())
    , m_label(new QLabel())
    , m_groupProperty(0)
{
    setAutoFillBackground(true);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addWidget(m_box);
    layout->addWidget(m_label);
    m_label->hide();

    connect(m_box, SIGNAL(currentIndexChanged(int)),
            this, SLOT(indexChanged(int)));

    setLayout(layout);
}

ObsoleteGroupPropertyEdit::~ObsoleteGroupPropertyEdit()
{
}

void ObsoleteGroupPropertyEdit::setGroupProperty(GroupProperty_t groupProperty)
{
    if(groupProperty) {
        m_groupProperty = groupProperty;
        processGroup();
    }
}

void ObsoleteGroupPropertyEdit::processGroup()
{
    disconnect(m_box, SIGNAL(currentIndexChanged(int)),
            this, SLOT(indexChanged(int)));

    if(m_box->count() != m_groupProperty->itemLabels().size()) {
        m_box->clear();
        m_box->insertItems(0, m_groupProperty->itemLabels());
    }
    m_box->setCurrentIndex(m_groupProperty->currentIndex());

    connect(m_box, SIGNAL(currentIndexChanged(int)),
            this, SLOT(indexChanged(int)), Qt::UniqueConnection);
}

void ObsoleteGroupPropertyEdit::indexChanged(int index)
{
    m_groupProperty->setCurrentIndex(index);
}

QSize ObsoleteGroupPropertyEdit::sizeHint() const
{
    if(m_box)
        return m_box->sizeHint();

    if(m_label)
        return m_label->sizeHint();

    return QSize(100,10);
}

QSize ObsoleteGroupPropertyEdit::minimumSizeHint() const
{
    if(m_box)
        return m_box->minimumSizeHint();

    if(m_label)
        return m_label->minimumSizeHint();

    return QSize(100,10);
}

GroupProperty_t ObsoleteGroupPropertyEdit::group() const
{
    return m_groupProperty;
}

void ObsoleteGroupPropertyEdit::setGroup(GroupProperty_t group)
{
    setGroupProperty(group);
}


// -----------------------------------------------------------------------------
// ColorPropertyEdit
// -----------------------------------------------------------------------------

ObsoleteColorPropertyEdit::ObsoleteColorPropertyEdit(QWidget *parent)
    : QWidget(parent)
{
    setAutoFillBackground(true);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setMargin(2);
    layout->setSpacing(2);

    m_textLabel = new QLabel(this);
    m_textLabel->setText(colorValueText(m_colorProperty.getColor()));

    m_pixmapLabel = new QLabel(this);
    m_pixmapLabel->setPixmap(m_colorProperty.getPixmap());

    QToolButton *button = new QToolButton(this);
    button->setSizePolicy(QSizePolicy(QSizePolicy::Fixed,
                                      QSizePolicy::Preferred));
    button->setText(QLatin1String("..."));
    layout->insertSpacing(-1,1);
    layout->addWidget(m_pixmapLabel);
    layout->insertSpacing(-1,6);
    layout->addWidget(m_textLabel);
    layout->addStretch(1);
    layout->addWidget(button);

    setFocusPolicy(Qt::StrongFocus);
    setAttribute(Qt::WA_InputMethodEnabled);
    connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));
}


void ObsoleteColorPropertyEdit::buttonClicked()
{
    bool ok = false;
    QRgb oldRgba = m_colorProperty.getColor().rgba();
    QRgb newRgba = QColorDialog::getRgba(oldRgba, &ok, this);
    if (ok && newRgba != oldRgba) {
        m_colorProperty.setColor(QColor::fromRgba(newRgba));
        m_pixmapLabel->setPixmap(m_colorProperty.getPixmap());
        emit colorPropertyChanged(m_colorProperty);
    }

}

void ObsoleteColorPropertyEdit::setColorProperty(
        const ColorProperty &colorProperty)
{
    m_colorProperty = colorProperty;
    m_textLabel->setText(colorValueText(m_colorProperty.getColor()));
    m_pixmapLabel->setPixmap(m_colorProperty.getPixmap());
}

QString ObsoleteColorPropertyEdit::colorValueText(const QColor &c)
{
    return QString("[%1, %2, %3] (%4)")
           .arg(c.red()).arg(c.green()).arg(c.blue()).arg(c.alpha());
}


// -----------------------------------------------------------------------------
// ScientificDoublePropertyEdit
// -----------------------------------------------------------------------------


ObsoleteScientificDoublePropertyEdit::ObsoleteScientificDoublePropertyEdit(QWidget *parent)
    : QWidget(parent)
{
    setAutoFillBackground(true);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setMargin(0);
    layout->setSpacing(0);

    m_lineEdit = new QLineEdit(this);
    layout->addWidget(m_lineEdit);

    m_validator  = new QDoubleValidator(0.0, 1e+100, 1000, this);
    m_validator->setNotation(QDoubleValidator::ScientificNotation);
    m_lineEdit->setValidator(m_validator);

    connect(m_lineEdit, SIGNAL(editingFinished()),
            this, SLOT(onEditingFinished()));

    setLayout(layout);
}

void ObsoleteScientificDoublePropertyEdit::setScientificDoubleProperty(
        const ObsoleteScientificDoubleProperty &doubleProperty)
{
    m_lineEdit->setText(doubleProperty.getText());
    m_scientificDoubleProperty = doubleProperty;
}

void ObsoleteScientificDoublePropertyEdit::onEditingFinished()
{
    double new_value = m_lineEdit->text().toDouble();
    if(new_value != m_scientificDoubleProperty.getValue()) {
        ObsoleteScientificDoubleProperty doubleProperty(new_value);
        setScientificDoubleProperty(doubleProperty);
        emit scientificDoublePropertyChanged(m_scientificDoubleProperty);
    }
}

QSize ObsoleteScientificDoublePropertyEdit::sizeHint() const
{
    return m_lineEdit->sizeHint();
}

QSize ObsoleteScientificDoublePropertyEdit::minimumSizeHint() const
{
    return m_lineEdit->minimumSizeHint();
}

// -----------------------------------------------------------------------------
// ComboPropertyEdit
// -----------------------------------------------------------------------------

//ComboPropertyEdit::ComboPropertyEdit(QWidget *parent)
//    : QWidget(parent)
//    , m_comboBox(0)
//{
//    m_comboBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//}

ObsoleteComboPropertyEdit::ObsoleteComboPropertyEdit(QWidget *parent)
    : QComboBox(parent)
{
    setAutoFillBackground(true);
}

//ComboPropertyEdit::~ComboPropertyEdit()
//{
//}

void ObsoleteComboPropertyEdit::setComboProperty(
        const ComboProperty &combo_property)
{
    m_combo_property = combo_property;
//    if (!m_comboBox) {
//        m_comboBox = new QComboBox(this);
//    }

    disconnect(this, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(onCurrentIndexChanged(QString)));

//    m_comboBox->clear();
    if(count() !=m_combo_property.getValues().size()) {
        clear();
        QStringList value_list = m_combo_property.getValues();

        addItems(value_list);

        int index(0);
        foreach(QString descr, m_combo_property.toolTips())
            setItemData(index++, descr, Qt::ToolTipRole);

    }
    setCurrentText(comboValueText());

    connect(this, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(onCurrentIndexChanged(QString)));
}

QString ObsoleteComboPropertyEdit::comboValueText()
{
    return m_combo_property.getValue();
}

//QSize ComboPropertyEdit::sizeHint() const
//{
//    Q_ASSERT(m_comboBox);
//    return m_comboBox->sizeHint();

//}

//QSize ComboPropertyEdit::minimumSizeHint() const
//{
//    Q_ASSERT(m_comboBox);
//    return m_comboBox->minimumSizeHint();
//}

void ObsoleteComboPropertyEdit::onCurrentIndexChanged(QString current_value)
{
    m_combo_property.setValue(current_value);
    emit comboPropertyChanged(m_combo_property);
}


