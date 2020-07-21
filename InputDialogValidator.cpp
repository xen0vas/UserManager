#include "InputDialogValidator.h"
#include <QDialogButtonBox>
#include <QRegExpValidator>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>


InputDialogValidator::InputDialogValidator(QWidget *parent, Qt::WindowFlags flags) : QDialog(parent)
{

this->setAttribute(Qt::WA_QuitOnClose, false);

if(flags!=0) setWindowFlags(flags);

QVBoxLayout *l=new QVBoxLayout(this);

label=new QLabel(this);

// Security Fix : Whitelisted characters digits and symbols
QRegExp regExp("^[a-zA-Z0-9-_]+$");
//regExp=QRegExp("^[a-zA-Z0-9-_]{0,12}$");

validator=new QRegExpValidator(regExp);

text=new QLineEdit(this);

text->setValidator(validator);

connect(text, SIGNAL(textChanged(QString)), this, SLOT(checkValid(QString)));

buttonBox=new QDialogButtonBox(QDialogButtonBox::Ok|QDialogButtonBox::Cancel, Qt::Horizontal, this);

connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

l->addWidget(label);
l->addWidget(text);
l->addWidget(buttonBox);
}

InputDialogValidator::~InputDialogValidator()
{

}

void InputDialogValidator::setTitle(const QString &title){
    setWindowTitle(title);
}

void InputDialogValidator::setLabelText(const QString &label){
    this->label->setText(label);
}

void InputDialogValidator::setText(const QString &text)
{
    this->text->setText(text);
}

void InputDialogValidator::setRegExp(const QRegExp &regExp){
    validator->setRegExp(regExp);
    checkValid(text->text());
}

QString InputDialogValidator::getLabelText(){
    return label->text();
}

QString InputDialogValidator::getText(){
    return text->text();
}

void InputDialogValidator::checkValid(const QString &text)
{
    QString _text=QString(text);
    int pos=0;
    bool valid=validator->validate(_text, pos)==QRegExpValidator::Acceptable;
    buttonBox->button(QDialogButtonBox::Ok);
    buttonBox->setEnabled(valid);
}

QString InputDialogValidator::getText(QWidget *parent, const QString &title, const QString &label, const QString &text, const QRegExp &regExp, bool *ok, Qt::WindowFlags flags)
{
    InputDialogValidator *r = new InputDialogValidator(parent, flags);

    r->setTitle(title);
    r->setLabelText(label);
    r->setText(text);
    r->setRegExp(regExp);

    *ok = r->exec()==QDialog::Accepted;

    if(*ok)
        return r->getText();
    else
        return QString();
}

