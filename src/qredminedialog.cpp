#include "qredminedialog.h"

#include <QLineEdit>
#include <QFormLayout>
#include <QLabel>
#include <QDialogButtonBox>


QRedmineDialog::QRedmineDialog(const QString &subject, const QString &description) :
    _subject(new QLineEdit(subject, this)),
    _description(new QLineEdit(description, this))
{
    // Use a layout allowing to have a label next to each field
    QFormLayout* form = new QFormLayout();

    // Add some text above the fields
    form->addRow(new QLabel("Redmine issue"));

    // Add the lineEdits with their respective labels
    form->addRow( QString("Subject"), _subject);
    form->addRow( QString("Description"), _description);

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                                                       Qt::Horizontal, this);
    form->addRow(buttonBox);
    QObject::connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
    this->setLayout(form);
}

void QRedmineDialog::showDialog(bool &success)
{
    success = exec() == QDialog::Accepted;
}
