/********************************************************************************
** Form generated from reading UI file 'HashingAlgorithm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HASHINGALGORITHM_H
#define UI_HASHINGALGORITHM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_HashingAlgorithm
{
public:
    QVBoxLayout *verticalLayout_2;
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
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *pass;
    QSpacerItem *verticalSpacer_12;
    QLabel *label_3;
    QLineEdit *pass2;
    QSpacerItem *verticalSpacer_14;
    QSpacerItem *verticalSpacer_11;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *okBtn;
    QPushButton *Save;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *HashingAlgorithm)
    {
        if (HashingAlgorithm->objectName().isEmpty())
            HashingAlgorithm->setObjectName(QStringLiteral("HashingAlgorithm"));
        HashingAlgorithm->resize(366, 415);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        HashingAlgorithm->setFont(font);
        verticalLayout_2 = new QVBoxLayout(HashingAlgorithm);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        UserLabel = new QLabel(HashingAlgorithm);
        UserLabel->setObjectName(QStringLiteral("UserLabel"));
        UserLabel->setMaximumSize(QSize(91, 16777215));

        horizontalLayout_5->addWidget(UserLabel);

        UserNameLabel = new QLabel(HashingAlgorithm);
        UserNameLabel->setObjectName(QStringLiteral("UserNameLabel"));
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
        NameLabelHidden->setObjectName(QStringLiteral("NameLabelHidden"));
        sizePolicy.setHeightForWidth(NameLabelHidden->sizePolicy().hasHeightForWidth());
        NameLabelHidden->setSizePolicy(sizePolicy);
        NameLabelHidden->setMaximumSize(QSize(151, 16777215));

        horizontalLayout_5->addWidget(NameLabelHidden);


        verticalLayout_2->addLayout(horizontalLayout_5);

        verticalSpacer_13 = new QSpacerItem(345, 28, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_2->addItem(verticalSpacer_13);

        groupBox = new QGroupBox(HashingAlgorithm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        Sha512rdb = new QRadioButton(groupBox);
        Sha512rdb->setObjectName(QStringLiteral("Sha512rdb"));

        horizontalLayout_4->addWidget(Sha512rdb);

        MD5rdb = new QRadioButton(groupBox);
        MD5rdb->setObjectName(QStringLiteral("MD5rdb"));

        horizontalLayout_4->addWidget(MD5rdb);

        Sha256rdb = new QRadioButton(groupBox);
        Sha256rdb->setObjectName(QStringLiteral("Sha256rdb"));

        horizontalLayout_4->addWidget(Sha256rdb);

        Blowfishrdb = new QRadioButton(groupBox);
        Blowfishrdb->setObjectName(QStringLiteral("Blowfishrdb"));

        horizontalLayout_4->addWidget(Blowfishrdb);

        Sha256rdb->raise();
        MD5rdb->raise();
        Sha512rdb->raise();
        Blowfishrdb->raise();

        verticalLayout_2->addWidget(groupBox);

        verticalSpacer_10 = new QSpacerItem(348, 34, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_2->addItem(verticalSpacer_10);

        groupBox_2 = new QGroupBox(HashingAlgorithm);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        pass = new QLineEdit(groupBox_2);
        pass->setObjectName(QStringLiteral("pass"));

        verticalLayout->addWidget(pass);

        verticalSpacer_12 = new QSpacerItem(321, 14, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_12);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        pass2 = new QLineEdit(groupBox_2);
        pass2->setObjectName(QStringLiteral("pass2"));

        verticalLayout->addWidget(pass2);

        verticalSpacer_14 = new QSpacerItem(321, 15, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_14);


        verticalLayout_2->addWidget(groupBox_2);

        verticalSpacer_11 = new QSpacerItem(348, 34, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_2->addItem(verticalSpacer_11);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        okBtn = new QPushButton(HashingAlgorithm);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/images/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        okBtn->setIcon(icon);

        horizontalLayout->addWidget(okBtn);

        Save = new QPushButton(HashingAlgorithm);
        Save->setObjectName(QStringLiteral("Save"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/images/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        Save->setIcon(icon1);

        horizontalLayout->addWidget(Save);

        horizontalSpacer_4 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout);

        groupBox->raise();
        groupBox_2->raise();

        retranslateUi(HashingAlgorithm);
        QObject::connect(okBtn, SIGNAL(clicked()), HashingAlgorithm, SLOT(close()));

        QMetaObject::connectSlotsByName(HashingAlgorithm);
    } // setupUi

    void retranslateUi(QDialog *HashingAlgorithm)
    {
        HashingAlgorithm->setWindowTitle(QApplication::translate("HashingAlgorithm", "Setup Password", Q_NULLPTR));
        UserLabel->setText(QApplication::translate("HashingAlgorithm", "User name :", Q_NULLPTR));
        UserNameLabel->setText(QString());
        NameLabelHidden->setText(QString());
        groupBox->setTitle(QApplication::translate("HashingAlgorithm", "Hashing Algorithm", Q_NULLPTR));
        Sha512rdb->setText(QApplication::translate("HashingAlgorithm", "SHA-512", Q_NULLPTR));
        MD5rdb->setText(QApplication::translate("HashingAlgorithm", "MD5", Q_NULLPTR));
        Sha256rdb->setText(QApplication::translate("HashingAlgorithm", "SHA-256", Q_NULLPTR));
        Blowfishrdb->setText(QApplication::translate("HashingAlgorithm", "Blowfish", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        label_2->setText(QApplication::translate("HashingAlgorithm", "Password: ", Q_NULLPTR));
        label_3->setText(QApplication::translate("HashingAlgorithm", "Confirm: ", Q_NULLPTR));
        okBtn->setText(QApplication::translate("HashingAlgorithm", "Close", Q_NULLPTR));
        Save->setText(QApplication::translate("HashingAlgorithm", "Accept", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HashingAlgorithm: public Ui_HashingAlgorithm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HASHINGALGORITHM_H
