/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "dirlist.h"
#include "mytreewidget.h"
#include "textviewer.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionScan_Directory;
    QAction *actionExit;
    QAction *actionAbout;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter_2;
    QSplitter *splitter;
    MyTreeWidget *treeWidget;
    TextViewer *textViewer;
    DirList *dirWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addFileButton;
    QSpacerItem *horizontalSpacer;
    QLabel *fileNameLabel;
    QLabel *foundAmountLabel;
    QPushButton *prevButton;
    QPushButton *nextButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *finderLabel;
    QTextEdit *lineEdit;
    QProgressBar *progressBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 708);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionScan_Directory = new QAction(MainWindow);
        actionScan_Directory->setObjectName(QStringLiteral("actionScan_Directory"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setMinimumSize(QSize(10, 0));
        centralWidget->setBaseSize(QSize(0, 10));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        treeWidget = new MyTreeWidget(splitter);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setAnimated(true);
        splitter->addWidget(treeWidget);
        treeWidget->header()->setMinimumSectionSize(100);
        treeWidget->header()->setStretchLastSection(false);
        textViewer = new TextViewer(splitter);
        textViewer->setObjectName(QStringLiteral("textViewer"));
        splitter->addWidget(textViewer);
        splitter_2->addWidget(splitter);
        dirWidget = new DirList(splitter_2);
        dirWidget->setObjectName(QStringLiteral("dirWidget"));
        splitter_2->addWidget(dirWidget);

        gridLayout->addWidget(splitter_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addFileButton = new QPushButton(centralWidget);
        addFileButton->setObjectName(QStringLiteral("addFileButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(addFileButton->sizePolicy().hasHeightForWidth());
        addFileButton->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(addFileButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        fileNameLabel = new QLabel(centralWidget);
        fileNameLabel->setObjectName(QStringLiteral("fileNameLabel"));

        horizontalLayout->addWidget(fileNameLabel);

        foundAmountLabel = new QLabel(centralWidget);
        foundAmountLabel->setObjectName(QStringLiteral("foundAmountLabel"));

        horizontalLayout->addWidget(foundAmountLabel);

        prevButton = new QPushButton(centralWidget);
        prevButton->setObjectName(QStringLiteral("prevButton"));

        horizontalLayout->addWidget(prevButton);

        nextButton = new QPushButton(centralWidget);
        nextButton->setObjectName(QStringLiteral("nextButton"));

        horizontalLayout->addWidget(nextButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        finderLabel = new QLabel(centralWidget);
        finderLabel->setObjectName(QStringLiteral("finderLabel"));

        horizontalLayout_2->addWidget(finderLabel);

        lineEdit = new QTextEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy3);
        lineEdit->setMinimumSize(QSize(2, 2));
        lineEdit->setBaseSize(QSize(0, 0));

        horizontalLayout_2->addWidget(lineEdit);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MegaFinder", nullptr));
        actionScan_Directory->setText(QApplication::translate("MainWindow", "&Scan Directory...", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "&Exit", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "About", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Directory", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Filename", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = dirWidget->headerItem();
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "Directory", nullptr));
        addFileButton->setText(QApplication::translate("MainWindow", "Add directory", nullptr));
        fileNameLabel->setText(QString());
        foundAmountLabel->setText(QString());
        prevButton->setText(QApplication::translate("MainWindow", "Prev usage", nullptr));
        nextButton->setText(QApplication::translate("MainWindow", "Next usage", nullptr));
        finderLabel->setText(QApplication::translate("MainWindow", " Find:", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "Fi&le", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
