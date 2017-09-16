/********************************************************************************
** Form generated from reading UI file 'HashingAlgorithm.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HASHINGALGORITHM_H
#define UI_HASHINGALGORITHM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_HashingAlgorithm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *UserLabel;
    QLabel *UserNameLabel;
    QSpacerItem *horizontalSpacer_3;
    QLabel *NameLabelHidden;
    QSpacerItem *verticalSpacer_13;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *Sha512rdb;
    QRadioButton *MD5rdb;
    QRadioButton *Sha256rdb;
    QRadioButton *Blowfishrdb;
    QSpacerItem *verticalSpacer_10;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *pass;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_12;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *pass2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_11;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *okBtn;
    QPushButton *Save;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *HashingAlgorithm)
    {
        if (HashingAlgorithm->objectName().isEmpty())
            HashingAlgorithm->setObjectName(QString::fromUtf8("HashingAlgorithm"));
        HashingAlgorithm->resize(363, 364);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        HashingAlgorithm->setFont(font);
        verticalLayout = new QVBoxLayout(HashingAlgorithm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        UserLabel = new QLabel(HashingAlgorithm);
        UserLabel->setObjectName(QString::fromUtf8("UserLabel"));
        UserLabel->setMaximumSize(QSize(91, 16777215));

        horizontalLayout_5->addWidget(UserLabel);

        UserNameLabel = new QLabel(HashingAlgorithm);
        UserNameLabel->setObjectName(QString::fromUtf8("UserNameLabel"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UserNameLabel->sizePolicy().hasHeightForWidth());
        UserNameLabel->setSizePolicy(sizePolicy);
        UserNameLabel->setMaximumSize(QSize(151, 16777215));

        horizontalLayout_5->addWidget(UserNameLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        NameLabelHidden = new QLabel(HashingAlgorithm);
        NameLabelHidden->setObjectName(QString::fromUtf8("NameLabelHidden"));
        sizePolicy.setHeightForWidth(NameLabelHidden->sizePolicy().hasHeightForWidth());
        NameLabelHidden->setSizePolicy(sizePolicy);
        NameLabelHidden->setMaximumSize(QSize(151, 16777215));

        horizontalLayout_5->addWidget(NameLabelHidden);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_13 = new QSpacerItem(345, 28, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_13);

        groupBox = new QGroupBox(HashingAlgorithm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        Sha512rdb = new QRadioButton(groupBox);
        Sha512rdb->setObjectName(QString::fromUtf8("Sha512rdb"));

        horizontalLayout_4->addWidget(Sha512rdb);

        MD5rdb = new QRadioButton(groupBox);
        MD5rdb->setObjectName(QString::fromUtf8("MD5rdb"));

        horizontalLayout_4->addWidget(MD5rdb);

        Sha256rdb = new QRadioButton(groupBox);
        Sha256rdb->setObjectName(QString::fromUtf8("Sha256rdb"));

        horizontalLayout_4->addWidget(Sha256rdb);

        Blowfishrdb = new QRadioButton(groupBox);
        Blowfishrdb->setObjectName(QString::fromUtf8("Blowfishrdb"));

        horizontalLayout_4->addWidget(Blowfishrdb);

        Sha256rdb->raise();
        MD5rdb->raise();
        Sha512rdb->raise();
        Blowfishrdb->raise();

        verticalLayout->addWidget(groupBox);

        verticalSpacer_10 = new QSpacerItem(348, 34, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_10);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(HashingAlgorithm);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        pass = new QLineEdit(HashingAlgorithm);
        pass->setObjectName(QString::fromUtf8("pass"));

        horizontalLayout_3->addWidget(pass);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_12 = new QSpacerItem(348, 34, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_12);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(HashingAlgorithm);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        pass2 = new QLineEdit(HashingAlgorithm);
        pass2->setObjectName(QString::fromUtf8("pass2"));

        horizontalLayout_2->addWidget(pass2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_11 = new QSpacerItem(348, 34, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_11);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        okBtn = new QPushButton(HashingAlgorithm);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/images/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        okBtn->setIcon(icon);

        horizontalLayout->addWidget(okBtn);

        Save = new QPushButton(HashingAlgorithm);
        Save->setObjectName(QString::fromUtf8("Save"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/images/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        Save->setIcon(icon1);

        horizontalLayout->addWidget(Save);

        horizontalSpacer_4 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        groupBox->raise();
        NameLabelHidden->raise();
        pass2->raise();

        retranslateUi(HashingAlgorithm);
        QObject::connect(okBtn, SIGNAL(clicked()), HashingAlgorithm, SLOT(close()));

        QMetaObject::connectSlotsByName(HashingAlgorithm);
    } // setupUi

    void retranslateUi(QDialog *HashingAlgorithm)
    {
        HashingAlgorithm->setWindowTitle(QApplication::translate("HashingAlgorithm", "Setup Password", 0, QApplication::UnicodeUTF8));
        UserLabel->setText(QApplication::translate("HashingAlgorithm", "User name :", 0, QApplication::UnicodeUTF8));
        UserNameLabel->setText(QString());
        NameLabelHidden->setText(QString());
        groupBox->setTitle(QApplication::translate("HashingAlgorithm", "Hashing Algorithm", 0, QApplication::UnicodeUTF8));
        Sha512rdb->setText(QApplication::translate("HashingAlgorithm", "SHA-512", 0, QApplication::UnicodeUTF8));
        MD5rdb->setText(QApplication::translate("HashingAlgorithm", "MD5", 0, QApplication::UnicodeUTF8));
        Sha256rdb->setText(QApplication::translate("HashingAlgorithm", "SHA-256", 0, QApplication::UnicodeUTF8));
        Blowfishrdb->setText(QApplication::translate("HashingAlgorithm", "Blowfish", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("HashingAlgorithm", "Password: ", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HashingAlgorithm", "Verify:         ", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("HashingAlgorithm", "Close", 0, QApplication::UnicodeUTF8));
        Save->setText(QApplication::translate("HashingAlgorithm", "Accept", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HashingAlgorithm: public Ui_HashingAlgorithm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HASHINGALGORITHM_H
