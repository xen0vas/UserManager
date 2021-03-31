/********************************************************************************
** Form generated from reading UI file 'UserProperties.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERPROPERTIES_H
#define UI_USERPROPERTIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserProperties
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QLabel *FullName;
    QLabel *Office1;
    QLabel *UserID;
    QLineEdit *HomeDirEdit;
    QLabel *Home;
    QCheckBox *checkBox;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *UserLogin;
    QComboBox *shellConnect;
    QSpacerItem *verticalSpacer_7;
    QLabel *Office2;
    QLineEdit *office2Edit;
    QSpacerItem *verticalSpacer_8;
    QLabel *ShellConn;
    QLineEdit *FullNameEdit;
    QPushButton *passBtn;
    QLabel *AccountDisabled;
    QSpacerItem *verticalSpacer_5;
    QLineEdit *office1Edit;
    QLineEdit *uidEdit;
    QLabel *label_17;
    QLabel *Address;
    QLineEdit *addressEdit;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_4;
    QLabel *NameLabel;
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
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *add;
    QPushButton *closeBtn;
    QPushButton *ok;

    void setupUi(QDialog *UserProperties)
    {
        if (UserProperties->objectName().isEmpty())
            UserProperties->setObjectName(QStringLiteral("UserProperties"));
        UserProperties->resize(741, 471);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/images/adduser.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        UserProperties->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(UserProperties);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(UserProperties);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        FullName = new QLabel(tab_2);
        FullName->setObjectName(QStringLiteral("FullName"));
        FullName->setScaledContents(true);
        FullName->setWordWrap(false);

        gridLayout_2->addWidget(FullName, 4, 0, 1, 1);

        Office1 = new QLabel(tab_2);
        Office1->setObjectName(QStringLiteral("Office1"));
        Office1->setScaledContents(true);
        Office1->setWordWrap(false);

        gridLayout_2->addWidget(Office1, 10, 0, 1, 1);

        UserID = new QLabel(tab_2);
        UserID->setObjectName(QStringLiteral("UserID"));
        UserID->setScaledContents(true);
        UserID->setWordWrap(false);

        gridLayout_2->addWidget(UserID, 2, 0, 1, 1);

        HomeDirEdit = new QLineEdit(tab_2);
        HomeDirEdit->setObjectName(QStringLiteral("HomeDirEdit"));

        gridLayout_2->addWidget(HomeDirEdit, 8, 1, 1, 4);

        Home = new QLabel(tab_2);
        Home->setObjectName(QStringLiteral("Home"));
        Home->setScaledContents(true);
        Home->setWordWrap(false);

        gridLayout_2->addWidget(Home, 8, 0, 1, 1);

        checkBox = new QCheckBox(tab_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/images/lock.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkBox->setIcon(icon1);
        checkBox->setChecked(true);

        gridLayout_2->addWidget(checkBox, 16, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer, 15, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer_2, 13, 0, 1, 1);

        UserLogin = new QLabel(tab_2);
        UserLogin->setObjectName(QStringLiteral("UserLogin"));
        UserLogin->setScaledContents(true);
        UserLogin->setWordWrap(false);

        gridLayout_2->addWidget(UserLogin, 0, 0, 1, 1);

        shellConnect = new QComboBox(tab_2);
        shellConnect->setObjectName(QStringLiteral("shellConnect"));

        gridLayout_2->addWidget(shellConnect, 6, 1, 1, 4);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer_7, 3, 0, 1, 1);

        Office2 = new QLabel(tab_2);
        Office2->setObjectName(QStringLiteral("Office2"));
        Office2->setScaledContents(true);
        Office2->setWordWrap(false);

        gridLayout_2->addWidget(Office2, 12, 0, 1, 1);

        office2Edit = new QLineEdit(tab_2);
        office2Edit->setObjectName(QStringLiteral("office2Edit"));

        gridLayout_2->addWidget(office2Edit, 12, 1, 1, 4);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer_8, 1, 0, 1, 1);

        ShellConn = new QLabel(tab_2);
        ShellConn->setObjectName(QStringLiteral("ShellConn"));
        ShellConn->setScaledContents(true);
        ShellConn->setWordWrap(false);

        gridLayout_2->addWidget(ShellConn, 6, 0, 1, 1);

        FullNameEdit = new QLineEdit(tab_2);
        FullNameEdit->setObjectName(QStringLiteral("FullNameEdit"));

        gridLayout_2->addWidget(FullNameEdit, 4, 1, 1, 4);

        passBtn = new QPushButton(tab_2);
        passBtn->setObjectName(QStringLiteral("passBtn"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../resources/images/keys.png"), QSize(), QIcon::Normal, QIcon::Off);
        passBtn->setIcon(icon2);

        gridLayout_2->addWidget(passBtn, 0, 4, 1, 1);

        AccountDisabled = new QLabel(tab_2);
        AccountDisabled->setObjectName(QStringLiteral("AccountDisabled"));
        AccountDisabled->setScaledContents(true);
        AccountDisabled->setWordWrap(false);

        gridLayout_2->addWidget(AccountDisabled, 16, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer_5, 7, 0, 1, 1);

        office1Edit = new QLineEdit(tab_2);
        office1Edit->setObjectName(QStringLiteral("office1Edit"));

        gridLayout_2->addWidget(office1Edit, 10, 1, 1, 4);

        uidEdit = new QLineEdit(tab_2);
        uidEdit->setObjectName(QStringLiteral("uidEdit"));

        gridLayout_2->addWidget(uidEdit, 2, 1, 1, 4);

        label_17 = new QLabel(tab_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setPixmap(QPixmap(QString::fromUtf8("../../../resources/images/keys.png")));
        label_17->setScaledContents(true);
        label_17->setWordWrap(false);

        gridLayout_2->addWidget(label_17, 0, 3, 1, 1);

        Address = new QLabel(tab_2);
        Address->setObjectName(QStringLiteral("Address"));
        Address->setScaledContents(true);
        Address->setWordWrap(false);

        gridLayout_2->addWidget(Address, 14, 0, 1, 1);

        addressEdit = new QLineEdit(tab_2);
        addressEdit->setObjectName(QStringLiteral("addressEdit"));

        gridLayout_2->addWidget(addressEdit, 14, 1, 1, 4);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer_3, 11, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer_6, 5, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_2->addItem(verticalSpacer_4, 9, 0, 1, 1);

        NameLabel = new QLabel(tab_2);
        NameLabel->setObjectName(QStringLiteral("NameLabel"));

        gridLayout_2->addWidget(NameLabel, 0, 1, 1, 2);

        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 2);

        timeDate = new QLabel(tab);
        timeDate->setObjectName(QStringLiteral("timeDate"));

        gridLayout_3->addWidget(timeDate, 0, 4, 1, 3);

        line = new QFrame(tab);
        line->setObjectName(QStringLiteral("line"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        line->setFont(font);
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::HLine);

        gridLayout_3->addWidget(line, 1, 0, 1, 7);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 2, 0, 1, 2);

        requires_Pass = new QCheckBox(tab);
        requires_Pass->setObjectName(QStringLiteral("requires_Pass"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(requires_Pass->sizePolicy().hasHeightForWidth());
        requires_Pass->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(requires_Pass, 3, 0, 1, 1);

        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_3->addWidget(label_9, 3, 1, 1, 4);

        max = new QSpinBox(tab);
        max->setObjectName(QStringLiteral("max"));
        max->setLayoutDirection(Qt::LeftToRight);
        max->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        max->setMinimum(0);
        max->setMaximum(99999);

        gridLayout_3->addWidget(max, 3, 6, 1, 1);

        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_3->addWidget(label_13, 5, 0, 1, 4);

        warn = new QSpinBox(tab);
        warn->setObjectName(QStringLiteral("warn"));
        warn->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        warn->setMinimum(-1);
        warn->setMaximum(99999);
        warn->setValue(0);

        gridLayout_3->addWidget(warn, 5, 6, 1, 1);

        label_14 = new QLabel(tab);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_3->addWidget(label_14, 7, 0, 1, 6);

        expire = new QSpinBox(tab);
        expire->setObjectName(QStringLiteral("expire"));
        expire->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        expire->setMinimum(-1);
        expire->setMaximum(99999);
        expire->setSingleStep(1);
        expire->setValue(0);

        gridLayout_3->addWidget(expire, 7, 6, 1, 1);

        enforce_Pass = new QCheckBox(tab);
        enforce_Pass->setObjectName(QStringLiteral("enforce_Pass"));

        gridLayout_3->addWidget(enforce_Pass, 9, 0, 1, 1);

        label_15 = new QLabel(tab);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_3->addWidget(label_15, 9, 1, 1, 4);

        min = new QSpinBox(tab);
        min->setObjectName(QStringLiteral("min"));
        min->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        min->setMinimum(-1);
        min->setMaximum(99999);

        gridLayout_3->addWidget(min, 9, 6, 1, 1);

        line_2 = new QFrame(tab);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFont(font);
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setLineWidth(1);
        line_2->setMidLineWidth(0);
        line_2->setFrameShape(QFrame::HLine);

        gridLayout_3->addWidget(line_2, 11, 0, 1, 7);

        label_16 = new QLabel(tab);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_3->addWidget(label_16, 13, 1, 1, 1);

        days = new QSpinBox(tab);
        days->setObjectName(QStringLiteral("days"));
        days->setValue(1);

        gridLayout_3->addWidget(days, 13, 2, 1, 1);

        months = new QComboBox(tab);
        months->setObjectName(QStringLiteral("months"));

        gridLayout_3->addWidget(months, 13, 3, 1, 2);

        years = new QSpinBox(tab);
        years->setObjectName(QStringLiteral("years"));
        years->setMaximum(8000);
        years->setValue(1970);

        gridLayout_3->addWidget(years, 13, 5, 1, 1);

        alway = new QCheckBox(tab);
        alway->setObjectName(QStringLiteral("alway"));

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
        tab_3->setObjectName(QStringLiteral("tab_3"));
        easyList = new QListWidget(tab_3);
        easyList->setObjectName(QStringLiteral("easyList"));
        easyList->setGeometry(QRect(0, 0, 311, 331));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(easyList->sizePolicy().hasHeightForWidth());
        easyList->setSizePolicy(sizePolicy2);
        userGroups = new QTreeView(tab_3);
        userGroups->setObjectName(QStringLiteral("userGroups"));
        userGroups->setGeometry(QRect(-3, 0, 721, 331));
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
        primGroupLabel->setObjectName(QStringLiteral("primGroupLabel"));
        primGroupLabel->setGeometry(QRect(440, 340, 109, 28));
        primGroupLabel->setStyleSheet(QStringLiteral("selection-color: red"));
        pglabel = new QLabel(tab_3);
        pglabel->setObjectName(QStringLiteral("pglabel"));
        pglabel->setGeometry(QRect(340, 344, 96, 20));
        sizePolicy1.setHeightForWidth(pglabel->sizePolicy().hasHeightForWidth());
        pglabel->setSizePolicy(sizePolicy1);
        pglabel->setScaledContents(false);
        pglabel->setWordWrap(true);
        easyCheckbox = new QCheckBox(tab_3);
        easyCheckbox->setObjectName(QStringLiteral("easyCheckbox"));
        easyCheckbox->setGeometry(QRect(4, 342, 163, 23));
        makePrimBtn = new QPushButton(tab_3);
        makePrimBtn->setObjectName(QStringLiteral("makePrimBtn"));
        makePrimBtn->setGeometry(QRect(572, 340, 126, 28));
        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(398, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        add = new QPushButton(UserProperties);
        add->setObjectName(QStringLiteral("add"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(add->sizePolicy().hasHeightForWidth());
        add->setSizePolicy(sizePolicy3);
        add->setIcon(icon);

        horizontalLayout->addWidget(add);

        closeBtn = new QPushButton(UserProperties);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/images/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeBtn->setIcon(icon3);

        horizontalLayout->addWidget(closeBtn);

        ok = new QPushButton(UserProperties);
        ok->setObjectName(QStringLiteral("ok"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/images/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        ok->setIcon(icon4);

        horizontalLayout->addWidget(ok);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(UserProperties);
        QObject::connect(closeBtn, SIGNAL(clicked()), UserProperties, SLOT(close()));
        QObject::connect(ok, SIGNAL(clicked()), UserProperties, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(UserProperties);
    } // setupUi

    void retranslateUi(QDialog *UserProperties)
    {
        UserProperties->setWindowTitle(QApplication::translate("UserProperties", "Properties", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QApplication::translate("UserProperties", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"> </p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        tabWidget->setWhatsThis(QApplication::translate("UserProperties", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        FullName->setText(QApplication::translate("UserProperties", "Full Name :", Q_NULLPTR));
        Office1->setText(QApplication::translate("UserProperties", "Office  1# :", Q_NULLPTR));
        UserID->setText(QApplication::translate("UserProperties", "User ID :", Q_NULLPTR));
        Home->setText(QApplication::translate("UserProperties", "Home Directory :", Q_NULLPTR));
        checkBox->setText(QString());
        UserLogin->setText(QApplication::translate("UserProperties", "User Login :", Q_NULLPTR));
        Office2->setText(QApplication::translate("UserProperties", "Office  2# :", Q_NULLPTR));
        ShellConn->setText(QApplication::translate("UserProperties", "Shell Connection :", Q_NULLPTR));
        passBtn->setText(QApplication::translate("UserProperties", "&Set Password ....", Q_NULLPTR));
        AccountDisabled->setText(QApplication::translate("UserProperties", "Account Disabled  :", Q_NULLPTR));
        label_17->setText(QString());
        Address->setText(QApplication::translate("UserProperties", "Address :", Q_NULLPTR));
        NameLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("UserProperties", "User &Info", Q_NULLPTR));
        label->setText(QApplication::translate("UserProperties", "Last Password Change :", Q_NULLPTR));
        timeDate->setText(QString());
        label_2->setText(QApplication::translate("UserProperties", "Password aging :", Q_NULLPTR));
        requires_Pass->setText(QString());
        label_9->setText(QApplication::translate("UserProperties", "Require new password after:", Q_NULLPTR));
        max->setSpecialValueText(QString());
        max->setSuffix(QApplication::translate("UserProperties", " days", Q_NULLPTR));
        max->setPrefix(QString());
        label_13->setText(QApplication::translate("UserProperties", "Warn before password expires :", Q_NULLPTR));
        warn->setSuffix(QApplication::translate("UserProperties", " days", Q_NULLPTR));
        label_14->setText(QApplication::translate("UserProperties", "Disable account after password expires:", Q_NULLPTR));
        expire->setSuffix(QApplication::translate("UserProperties", " days", Q_NULLPTR));
        enforce_Pass->setText(QString());
        label_15->setText(QApplication::translate("UserProperties", "Enforce minimum password age :", Q_NULLPTR));
        min->setSuffix(QApplication::translate("UserProperties", " days", Q_NULLPTR));
        label_16->setText(QApplication::translate("UserProperties", "Acount will expire on :", Q_NULLPTR));
        months->clear();
        months->insertItems(0, QStringList()
         << QApplication::translate("UserProperties", "January ", Q_NULLPTR)
         << QApplication::translate("UserProperties", "February", Q_NULLPTR)
         << QApplication::translate("UserProperties", "March", Q_NULLPTR)
         << QApplication::translate("UserProperties", "April", Q_NULLPTR)
         << QApplication::translate("UserProperties", "May", Q_NULLPTR)
         << QApplication::translate("UserProperties", "June ", Q_NULLPTR)
         << QApplication::translate("UserProperties", "July", Q_NULLPTR)
         << QApplication::translate("UserProperties", "August", Q_NULLPTR)
         << QApplication::translate("UserProperties", "September", Q_NULLPTR)
         << QApplication::translate("UserProperties", "October", Q_NULLPTR)
         << QApplication::translate("UserProperties", "November", Q_NULLPTR)
         << QApplication::translate("UserProperties", "December", Q_NULLPTR)
        );
        alway->setText(QApplication::translate("UserProperties", "Never", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("UserProperties", "Password &Manager", Q_NULLPTR));
        primGroupLabel->setText(QString());
        pglabel->setText(QApplication::translate("UserProperties", "Primary Group:", Q_NULLPTR));
        easyCheckbox->setText(QApplication::translate("UserProperties", "Privileges and groups", Q_NULLPTR));
        makePrimBtn->setText(QApplication::translate("UserProperties", "Set as Primary", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("UserProperties", "&Groups", Q_NULLPTR));
        add->setText(QApplication::translate("UserProperties", "Apply", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("UserProperties", "&Close", Q_NULLPTR));
        ok->setText(QApplication::translate("UserProperties", "&OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserProperties: public Ui_UserProperties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERPROPERTIES_H
