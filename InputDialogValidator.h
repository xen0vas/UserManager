#ifndef INPUTDIALOGVALIDATOR_H
#define INPUTDIALOGVALIDATOR_H

#include <QInputDialog>
#include <QLineEdit>
#include <QLabel>
#include <QDialogButtonBox>
#include <QRegExpValidator>

class InputDialogValidator : public QDialog{

    Q_OBJECT
public:
    InputDialogValidator(QWidget *parent, Qt::WindowFlags flags);
    ~InputDialogValidator();
    void setTitle(const QString &title);
    void setLabelText(const QString &label);
    void setText(const QString &text);
    void setRegExp(const QRegExp &regExp);

    QString getLabelText();
    QString getText();

    static QString getText(QWidget *parent, const QString &title, const QString &label, const QString &text, const QRegExp &regExp, bool *ok, Qt::WindowFlags flags=0);

signals:

private slots:
    void checkValid(const QString &text);

private:
    QLabel *label;
    QLineEdit *text;
    QDialogButtonBox *buttonBox;
    QRegExp regExp;
    QRegExpValidator *validator;
};

#endif // INPUTDIALOGVALIDATOR_H
