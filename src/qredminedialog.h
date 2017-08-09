#ifndef QREDMINEDIALOG_H
#define QREDMINEDIALOG_H

#include <QString>
#include <QDialog>
#include <QLineEdit>

class QRedmineDialog : public QDialog
{

    QLineEdit* _subject;
    QLineEdit* _description;

public:
    QRedmineDialog(const QString& subject, const QString& description);
    void showDialog(bool& success);

    const QString description() const { return _description->text(); }
    const QString subject() const { return _subject->text(); }

};

#endif // QREDMINEDIALOG_H
