/********************************************************************************
** Form generated from reading UI file 'UserProperties.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERPROPERTIES_H
#define UI_USERPROPERTIES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserProperties
{
public:
    QPushButton *closeBtn;
    QPushButton *ok;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLabel *NameLabel;
    QLabel *label_17;
    QPushButton *passBtn;
    QLabel *label_3;
    QLineEdit *uidEdit;
    QLabel *label_5;
    QLineEdit *FullNameEdit;
    QLabel *label_6;
    QComboBox *shellConnect;
    QLabel *label_7;
    QLineEdit *HomeDirEdit;
    QLabel *label_10;
    QLineEdit *office1Edit;
    QLabel *label_8;
    QLineEdit *office2Edit;
    QLabel *label_11;
    QLineEdit *addressEdit;
    QLabel *label_12;
    QCheckBox *checkBox;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_8;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLabel *timeDate;
    QFrame *line;
    QLabel *label_2;
    QCheckBox *requires_Pass;
    QLabel *label_9;
    QSpinBox *max;
    QLabel *label_13;
    QSpinBox *warn;
    QLabel *label_14;
    QSpinBox *expire;
    QCheckBox *enforce_Pass;
    QLabel *label_15;
    QSpinBox *min;
    QFrame *line_2;
    QLabel *label_16;
    QSpinBox *days;
    QComboBox *months;
    QSpinBox *years;
    QCheckBox *alway;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *verticalSpacer_10;
    QSpacerItem *verticalSpacer_11;
    QSpacerItem *verticalSpacer_12;
    QSpacerItem *verticalSpacer_13;
    QSpacerItem *verticalSpacer_14;
    QWidget *tab_3;
    QListWidget *easyList;
    QTreeView *userGroups;
    QLabel *primGroupLabel;
    QLabel *pglabel;
    QCheckBox *easyCheckbox;
    QPushButton *makePrimBtn;
    QPushButton *add;

    void setupUi(QDialog *UserProperties)
    {
        if (UserProperties->objectName().isEmpty())
            UserProperties->setObjectName(QString::fromUtf8("UserProperties"));
        UserProperties->resize(717, 467);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/images/adduser.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        UserProperties->setWindowIcon(icon);
        closeBtn = new QPushButton(UserProperties);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setGeometry(QRect(430, 430, 122, 28));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/images/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeBtn->setIcon(icon1);
        ok = new QPushButton(UserProperties);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(590, 430, 121, 28));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/images/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        ok->setIcon(icon2);
        tabWidget = new QTabWidget(UserProperties);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(4, 4, 711, 411));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setScaledContents(true);
        label_4->setWordWrap(false);

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        NameLabel = new QLabel(tab_2);
        NameLabel->setObjectName(QString::fromUtf8("NameLabel"));

        gridLayout_2->addWidget(NameLabel, 0, 1, 1, 2);

        label_17 = new QLabel(tab_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setPixmap(QPixmap(QString::fromUtf8("../../../resources/images/keys.png")));
        label_17->setScaledContents(true);
        label_17->setWordWrap(false);

        gridLayout_2->addWidget(label_17, 0, 3, 1, 1);

        passBtn = new QPushButton(tab_2);
        passBtn->setObjectName(QString::fromUtf8("passBtn"));

        gridLayout_2->addWidget(passBtn, 0, 4, 1, 1);

        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setScaledContents(true);
        label_3->setWordWrap(false);

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        uidEdit = new QLineEdit(tab_2);
        uidEdit->setObjectName(QString::fromUtf8("uidEdit"));

        gridLayout_2->addWidget(uidEdit, 2, 1, 1, 4);

        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setScaledContents(true);
        label_5->setWordWrap(false);

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        FullNameEdit = new QLineEdit(tab_2);
        FullNameEdit->setObjectName(QString::fromUtf8("FullNameEdit"));

        gridLayout_2->addWidget(FullNameEdit, 4, 1, 1, 4);

        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setScaledContents(true);
        label_6->setWordWrap(false);

        gridLayout_2->addWidget(label_6, 6, 0, 1, 1);

        shellConnect = new QComboBox(tab_2);
        shellConnect->setObjectName(QString::fromUtf8("shellConnect"));

        gridLayout_2->addWidget(shellConnect, 6, 1, 1, 4);

        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setScaledContents(true);
        label_7->setWordWrap(false);

        gridLayout_2->addWidget(label_7, 8, 0, 1, 1);

        HomeDirEdit = new QLineEdit(tab_2);
        HomeDirEdit->setObjectName(QString::fromUtf8("HomeDirEdit"));

        gridLayout_2->addWidget(HomeDirEdit, 8, 1, 1, 4);

        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setScaledContents(true);
        label_10->setWordWrap(false);

        gridLayout_2->addWidget(label_10, 10, 0, 1, 1);

        office1Edit = new QLineEdit(tab_2);
        office1Edit->setObjectName(QString::fromUtf8("office1Edit"));

        gridLayout_2->addWidget(office1Edit, 10, 1, 1, 4);

        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setScaledContents(true);
        label_8->setWordWrap(false);

        gridLayout_2->addWidget(label_8, 12, 0, 1, 1);

        office2Edit = new QLineEdit(tab_2);
        office2Edit->setObjectName(QString::fromUtf8("office2Edit"));

        gridLayout_2->addWidget(office2Edit, 12, 1, 1, 4);

        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setScaledContents(true);
        label_11->setWordWrap(false);

        gridLayout_2->addWidget(label_11, 14, 0, 1, 1);

        addressEdit = new QLineEdit(tab_2);
        addressEdit->setObjectName(QString::fromUtf8("addressEdit"));

        gridLayout_2->addWidget(addressEdit, 14, 1, 1, 4);

        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setScaledContents(true);
        label_12->setWordWrap(false);

        gridLayout_2->addWidget(label_12, 16, 0, 1, 1);

        checkBox = new QCheckBox(tab_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/images/lock.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkBox->setIcon(icon3);
        checkBox->setChecked(true);

        gridLayout_2->addWidget(checkBox, 16, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer, 15, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer_2, 13, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer_3, 11, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer_4, 9, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer_5, 7, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer_6, 5, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer_7, 3, 0, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer_8, 1, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 2);

        timeDate = new QLabel(tab);
        timeDate->setObjectName(QString::fromUtf8("timeDate"));

        gridLayout_3->addWidget(timeDate, 0, 4, 1, 3);

        line = new QFrame(tab);
        line->setObjectName(QString::fromUtf8("line"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        line->setFont(font);
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::HLine);

        gridLayout_3->addWidget(line, 1, 0, 1, 7);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 2, 0, 1, 2);

        requires_Pass = new QCheckBox(tab);
        requires_Pass->setObjectName(QString::fromUtf8("requires_Pass"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(requires_Pass->sizePolicy().hasHeightForWidth());
        requires_Pass->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(requires_Pass, 3, 0, 1, 1);

        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 3, 1, 1, 4);

        max = new QSpinBox(tab);
        max->setObjectName(QString::fromUtf8("max"));
        max->setLayoutDirection(Qt::LeftToRight);
        max->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        max->setMinimum(0);
        max->setMaximum(99999);

        gridLayout_3->addWidget(max, 3, 6, 1, 1);

        label_13 = new QLabel(tab);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 5, 0, 1, 4);

        warn = new QSpinBox(tab);
        warn->setObjectName(QString::fromUtf8("warn"));
        warn->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        warn->setMinimum(-1);
        warn->setMaximum(99999);
        warn->setValue(0);

        gridLayout_3->addWidget(warn, 5, 6, 1, 1);

        label_14 = new QLabel(tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 7, 0, 1, 6);

        expire = new QSpinBox(tab);
        expire->setObjectName(QString::fromUtf8("expire"));
        expire->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        expire->setMinimum(-1);
        expire->setMaximum(99999);
        expire->setSingleStep(1);
        expire->setValue(0);

        gridLayout_3->addWidget(expire, 7, 6, 1, 1);

        enforce_Pass = new QCheckBox(tab);
        enforce_Pass->setObjectName(QString::fromUtf8("enforce_Pass"));

        gridLayout_3->addWidget(enforce_Pass, 9, 0, 1, 1);

        label_15 = new QLabel(tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_3->addWidget(label_15, 9, 1, 1, 4);

        min = new QSpinBox(tab);
        min->setObjectName(QString::fromUtf8("min"));
        min->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        min->setMinimum(-1);
        min->setMaximum(99999);

        gridLayout_3->addWidget(min, 9, 6, 1, 1);

        line_2 = new QFrame(tab);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFont(font);
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(1);
        line_2->setMidLineWidth(0);
        line_2->setFrameShape(QFrame::HLine);

        gridLayout_3->addWidget(line_2, 11, 0, 1, 7);

        label_16 = new QLabel(tab);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_3->addWidget(label_16, 13, 1, 1, 1);

        days = new QSpinBox(tab);
        days->setObjectName(QString::fromUtf8("days"));
        days->setValue(1);

        gridLayout_3->addWidget(days, 13, 2, 1, 1);

        months = new QComboBox(tab);
        months->setObjectName(QString::fromUtf8("months"));

        gridLayout_3->addWidget(months, 13, 3, 1, 2);

        years = new QSpinBox(tab);
        years->setObjectName(QString::fromUtf8("years"));
        years->setMaximum(8000);
        years->setValue(1970);

        gridLayout_3->addWidget(years, 13, 5, 1, 1);

        alway = new QCheckBox(tab);
        alway->setObjectName(QString::fromUtf8("alway"));

        gridLayout_3->addWidget(alway, 13, 6, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_3->addItem(verticalSpacer_9, 4, 0, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_3->addItem(verticalSpacer_10, 6, 0, 1, 1);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_3->addItem(verticalSpacer_11, 8, 0, 1, 1);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_3->addItem(verticalSpacer_12, 10, 0, 1, 1);

        verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_3->addItem(verticalSpacer_13, 14, 1, 1, 1);

        verticalSpacer_14 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_3->addItem(verticalSpacer_14, 12, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        easyList = new QListWidget(tab_3);
        easyList->setObjectName(QString::fromUtf8("easyList"));
        easyList->setGeometry(QRect(0, 0, 311, 331));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(easyList->sizePolicy().hasHeightForWidth());
        easyList->setSizePolicy(sizePolicy2);
        userGroups = new QTreeView(tab_3);
        userGroups->setObjectName(QString::fromUtf8("userGroups"));
        userGroups->setGeometry(QRect(-3, 0, 701, 331));
        sizePolicy2.setHeightForWidth(userGroups->sizePolicy().hasHeightForWidth());
        userGroups->setSizePolicy(sizePolicy2);
        userGroups->setAutoFillBackground(false);
        userGroups->setFrameShape(QFrame::StyledPanel);
        userGroups->setFrameShadow(QFrame::Sunken);
        userGroups->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        userGroups->setEditTriggers(QAbstractItemView::NoEditTriggers);
        userGroups->setAlternatingRowColors(true);
        userGroups->setRootIsDecorated(false);
        userGroups->setUniformRowHeights(true);
        userGroups->setSortingEnabled(true);
        userGroups->setAnimated(true);
        primGroupLabel = new QLabel(tab_3);
        primGroupLabel->setObjectName(QString::fromUtf8("primGroupLabel"));
        primGroupLabel->setGeometry(QRect(440, 340, 109, 28));
        primGroupLabel->setStyleSheet(QString::fromUtf8("selection-color: red"));
        pglabel = new QLabel(tab_3);
        pglabel->setObjectName(QString::fromUtf8("pglabel"));
        pglabel->setGeometry(QRect(340, 344, 96, 20));
        sizePolicy1.setHeightForWidth(pglabel->sizePolicy().hasHeightForWidth());
        pglabel->setSizePolicy(sizePolicy1);
        pglabel->setScaledContents(false);
        pglabel->setWordWrap(true);
        easyCheckbox = new QCheckBox(tab_3);
        easyCheckbox->setObjectName(QString::fromUtf8("easyCheckbox"));
        easyCheckbox->setGeometry(QRect(4, 342, 163, 23));
        makePrimBtn = new QPushButton(tab_3);
        makePrimBtn->setObjectName(QString::fromUtf8("makePrimBtn"));
        makePrimBtn->setGeometry(QRect(572, 340, 126, 28));
        tabWidget->addTab(tab_3, QString());
        add = new QPushButton(UserProperties);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(590, 430, 122, 28));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(add->sizePolicy().hasHeightForWidth());
        add->setSizePolicy(sizePolicy3);
        add->setIcon(icon);

        retranslateUi(UserProperties);
        QObject::connect(closeBtn, SIGNAL(clicked()), UserProperties, SLOT(close()));
        QObject::connect(ok, SIGNAL(clicked()), UserProperties, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(UserProperties);
    } // setupUi

    void retranslateUi(QDialog *UserProperties)
    {
        UserProperties->setWindowTitle(QApplication::translate("UserProperties", "Properties", 0, QApplication::UnicodeUTF8));
        closeBtn->setText(QApplication::translate("UserProperties", "&Close", 0, QApplication::UnicodeUTF8));
        ok->setText(QApplication::translate("UserProperties", "&OK", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QApplication::translate("UserProperties", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"> </p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tabWidget->setWhatsThis(QApplication::translate("UserProperties", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        label_4->setText(QApplication::translate("UserProperties", "User Login :", 0, QApplication::UnicodeUTF8));
        NameLabel->setText(QString());
        label_17->setText(QString());
        passBtn->setText(QApplication::translate("UserProperties", "&Set Password ....", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("UserProperties", "User ID :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("UserProperties", "Full Name :", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("UserProperties", "Shell Connection :", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("UserProperties", "Home Directory :", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("UserProperties", "Office  1# :", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("UserProperties", "Office  2# :", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("UserProperties", "Address :", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("UserProperties", "Account Disabled  :", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("UserProperties", "User &Info", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("UserProperties", "Last Password Change :", 0, QApplication::UnicodeUTF8));
        timeDate->setText(QString());
        label_2->setText(QApplication::translate("UserProperties", "Password aging :", 0, QApplication::UnicodeUTF8));
        requires_Pass->setText(QString());
        label_9->setText(QApplication::translate("UserProperties", "Require new password after:", 0, QApplication::UnicodeUTF8));
        max->setSpecialValueText(QString());
        max->setSuffix(QApplication::translate("UserProperties", " days", 0, QApplication::UnicodeUTF8));
        max->setPrefix(QString());
        label_13->setText(QApplication::translate("UserProperties", "Warn before password expires :", 0, QApplication::UnicodeUTF8));
        warn->setSuffix(QApplication::translate("UserProperties", " days", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("UserProperties", "Disable account after password expires:", 0, QApplication::UnicodeUTF8));
        expire->setSuffix(QApplication::translate("UserProperties", " days", 0, QApplication::UnicodeUTF8));
        enforce_Pass->setText(QString());
        label_15->setText(QApplication::translate("UserProperties", "Enforce minimum password age :", 0, QApplication::UnicodeUTF8));
        min->setSuffix(QApplication::translate("UserProperties", " days", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("UserProperties", "Acount will expire on :", 0, QApplication::UnicodeUTF8));
        months->clear();
        months->insertItems(0, QStringList()
         << QApplication::translate("UserProperties", "January ", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UserProperties", "February", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UserProperties", "March", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UserProperties", "April", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UserProperties", "May", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UserProperties", "June ", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UserProperties", "July", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UserProperties", "August", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UserProperties", "September", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UserProperties", "October", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UserProperties", "November", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UserProperties", "December", 0, QApplication::UnicodeUTF8)
        );
        alway->setText(QApplication::translate("UserProperties", "Never", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("UserProperties", "Password &Manager", 0, QApplication::UnicodeUTF8));
        primGroupLabel->setText(QString());
        pglabel->setText(QApplication::translate("UserProperties", "Primary Group:", 0, QApplication::UnicodeUTF8));
        easyCheckbox->setText(QApplication::translate("UserProperties", "Privileges and groups", 0, QApplication::UnicodeUTF8));
        makePrimBtn->setText(QApplication::translate("UserProperties", "Set as Primary", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("UserProperties", "&Groups", 0, QApplication::UnicodeUTF8));
        add->setText(QApplication::translate("UserProperties", "Apply", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UserProperties: public Ui_UserProperties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERPROPERTIES_H
