#include "main_window.h"
#include "dbase/dbase.h"
#include "globals.h"
#include "msort.h"
#include <sstream>
#include <iostream>

using namespace std;
dbase db;

MainWindow::MainWindow()
{
    selectFile();

    // Title
    setWindowTitle("Welcome to Autobroker Database!");
    //overallLayout = new QHBoxLayout;
    buttonLayout= new QVBoxLayout;


    //buttonLayout->addWidget(inputData);
    // select = new QLabel("Please select from the following:") ;
    //buttonLayout->addWidget(select);
    //searchFile = new QPushButton("Add New User");
    //connect(searchFile, SIGNAL(clicked()), this, SLOT(newUserPopup()));
    //inputFile = new QPushButton("Add New Lead");
    //connect(inputFile, SIGNAL(clicked()), this, SLOT(showPopup()));

//	exportFile = new QRadioButton("Output to file");
    excelPopup();


    //  buttonLayout->addWidget(select);

    //  buttonLayout->addWidget(searchFile);
    //  buttonLayout->addWidget(inputFile);
    buttonLayout->addWidget(viewPlan);
    //buttonLayout->addWidget(exportFile);
    setLayout(buttonLayout);
    this->hide();
}

MainWindow::~MainWindow()
{
}
void MainWindow::excelPopup()
{   QLabel* leadLabel=new QLabel("Leads:");
    QLabel* customerLabel=new QLabel("Customers:");
    excelWindow=new QDialog();
    QGridLayout* excelLayout=new QGridLayout();
    QStringList leadHeaders;
    leadHeaders<<"date"<<"name"<<"cell"<<"Email"<<"Make"<<"Model"<<"Exterior"<<"Interior"<<"Year"<<"MSRP"<<"Options"<<"PriceQuoted"<<"Purpose"<<"Order Number";
    QStringList customerHeaders;
    customerHeaders<<"date"<<"name"<<"cell"<<"Email"<<"Make"<<"Model"<<"Down Payment"<<"Term"<<"Miles/Year"<<"Dotd"<<"purpose"<<"Order Number";
    vector<string> searchKey;
    vector<user> allUser=db.search(searchKey);
    QHBoxLayout* leadButtons=new QHBoxLayout();
    QPushButton* leadDelete=new QPushButton("Delete");
    QPushButton* leadEdit=new QPushButton("Edit");
    searchFile = new QPushButton("Add New Customer");
    connect(searchFile, SIGNAL(clicked()), this, SLOT(newUserPopup()));
    QPushButton* reminderButton=new QPushButton("reminder");
    connect(reminderButton,SIGNAL(clicked()),this,SLOT(reminder()));

    searchFile->setMaximumWidth(200);
    leadEdit->setMaximumWidth(200);
    inputFile = new QPushButton("Add New Potential Customer");
    connect(inputFile, SIGNAL(clicked()), this, SLOT(showPopup()));
    inputFile->setMaximumWidth(200);
    leadDelete->setMaximumWidth(200);
    leadButtons->addWidget(inputFile);
    leadButtons->addWidget(leadEdit);
    connect(leadEdit, SIGNAL(clicked()), this, SLOT(editUser()));
    connect(leadDelete, SIGNAL(clicked()), this, SLOT(deleteLead()));
    leadButtons->addWidget(leadDelete);
    // leadButtons->addWidget(leadEdit);
    QHBoxLayout* customerButtons=new QHBoxLayout();
    QPushButton* customerDelete=new QPushButton("Delete");
    customerDelete->setMaximumWidth(200);
    connect(customerDelete, SIGNAL(clicked()), this, SLOT(deleteCustomer()));
    QPushButton* customerEdit=new QPushButton("edit");
    customerEdit->setMaximumWidth(200);
    customerButtons->addWidget(searchFile);
    customerButtons->addWidget(customerEdit);
    customerButtons->addWidget(customerDelete);
    connect(customerEdit,SIGNAL(clicked()), this, SLOT(editCustomer()));
    //customerButtons->addWidget(customerEdit);
    int leadnum=0;
    int customernum=0;
    cout<<allUser.size();
    leadsWidget = new QTableWidget(leadnum, 14);	//leadsWidget->setRowCount(leadnum);
    customersWidget = new QTableWidget(customernum, 12);
    leadsWidget->setHorizontalHeaderLabels(leadHeaders);
    customersWidget->setHorizontalHeaderLabels(customerHeaders);
    for (int i=0; i<allUser.size(); i++)
        if (!allUser[i]._new)
        {
            leadsWidget->insertRow(leadnum);
            vector<string> tempN = allUser[i]._name;
            string nameInput1 = "";
            for (unsigned int j=0; j<tempN.size(); j++)
            {
                nameInput1 = nameInput1+tempN[j]+" ";
            }
            cout<<nameInput1;
            QTableWidgetItem* dateItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._date));
            leadsWidget->setItem(leadnum,0, dateItem);
            QTableWidgetItem* nameItem=new QTableWidgetItem(QString::fromStdString(nameInput1));
            leadsWidget->setItem(leadnum,1, nameItem);
            QTableWidgetItem* cellItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._cell));
            leadsWidget->setItem(leadnum,2, cellItem);
            QTableWidgetItem* emailItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._email));
            leadsWidget->setItem(leadnum,3, emailItem);
            QTableWidgetItem* makeItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._make));
            leadsWidget->setItem(leadnum,4, makeItem);
            QTableWidgetItem* modelItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._model));
            leadsWidget->setItem(leadnum,5, modelItem);
            QTableWidgetItem* exteriorItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._exterior));
            leadsWidget->setItem(leadnum,6, exteriorItem);
            QTableWidgetItem* interiorItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._interior));
            leadsWidget->setItem(leadnum,7, interiorItem);
            QTableWidgetItem* yearItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._year));
            leadsWidget->setItem(leadnum,8, yearItem);
            QTableWidgetItem* msrpItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._msrp));
            leadsWidget->setItem(leadnum,9, msrpItem);
            QTableWidgetItem* optionsItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._options));
            leadsWidget->setItem(leadnum,10, optionsItem);
            QTableWidgetItem* priceItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._price));
            leadsWidget->setItem(leadnum,11, priceItem);
            QTableWidgetItem* purposeItem;
            if (allUser[i]._lease)
                purposeItem=new QTableWidgetItem("lease");
            else
                purposeItem=new QTableWidgetItem("Purchase");
            leadsWidget->setItem(i,12, purposeItem);
            QTableWidgetItem* orderNItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._orderNumber));
            leadsWidget->setItem(leadnum,13,orderNItem);
            leadnum++;
        }
    for (int i=0; i<allUser.size(); i++)
        if (allUser[i]._new)
        {
            customersWidget->insertRow(customernum);
            vector<string> tempN = allUser[i]._name;
            string nameInput1 = "";
            for (unsigned int j=0; j<tempN.size(); j++)
            {
                nameInput1 = nameInput1+tempN[j]+" ";
            }
            cout<<nameInput1;
            QTableWidgetItem* dateItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._date));
            customersWidget->setItem(customernum,0, dateItem);
            QTableWidgetItem* nameItem=new QTableWidgetItem(QString::fromStdString(nameInput1));
            customersWidget->setItem(customernum,1, nameItem);
            QTableWidgetItem* cellItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._cell));
            customersWidget->setItem(customernum,2, cellItem);
            QTableWidgetItem* emailItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._email));
            customersWidget->setItem(customernum,3, emailItem);
            QTableWidgetItem* makeItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._make));
            customersWidget->setItem(customernum,4, makeItem);
            QTableWidgetItem* modelItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._model));
            customersWidget->setItem(customernum,5, modelItem);
            if (allUser[i]._lease)
            {
                QTableWidgetItem* downItem=new QTableWidgetItem(tr("%1").arg(allUser[i]._down));
                customersWidget->setItem(customernum,6, downItem);
                QTableWidgetItem* termItem=new QTableWidgetItem(tr("%1").arg(allUser[i]._term));
                customersWidget->setItem(customernum,7, termItem);
                QTableWidgetItem* milesItem=new QTableWidgetItem(tr("%1").arg(allUser[i]._miles));
                customersWidget->setItem(customernum,8, milesItem);
            }
            else
            {
                QTableWidgetItem* dotdItem=new QTableWidgetItem(tr("%1").arg(allUser[i]._dotd));
                customersWidget->setItem(customernum,9, dotdItem);
            }
            QTableWidgetItem* purposeItem;
            if (allUser[i]._lease)
                purposeItem=new QTableWidgetItem("lease");
            else
                purposeItem=new QTableWidgetItem("Purchase");
            customersWidget->setItem(i,10, purposeItem);
            QTableWidgetItem* orderNItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._orderNumber));
            customersWidget->setItem(leadnum,11,orderNItem);
            customernum++;

        }
    leadsWidget->setSortingEnabled(true);
    customersWidget->setSortingEnabled(true);
    searchInput = new QLineEdit();
    excelLayout->addWidget(searchInput);
    viewFile = new QPushButton("Search");
    connect(viewFile, SIGNAL(clicked()), this, SLOT(viewPopup()));
    excelLayout->addWidget(viewFile);
    excelLayout->addWidget(reminderButton);
    excelLayout->addWidget(leadLabel);
    excelLayout->addWidget(leadsWidget);
    excelLayout->addLayout(leadButtons,5,0);
    excelLayout->addWidget(customerLabel);
    excelLayout->addWidget(customersWidget);
    excelLayout->addLayout(customerButtons,10,0);
    excelWindow->setLayout(excelLayout);
    excelWindow->setWindowFlags(Qt::Window);
    excelWindow->setWindowState(Qt::WindowMaximized);
    //  excelWindow->resize(1200,600);
    excelWindow->exec();
}

void MainWindow::deleteLead()
{
    if(leadsWidget->currentRow()>=0)
    {
        int k=leadsWidget->currentRow();
        leadsWidget->removeRow(k);

        vector<string> searchKey;
        vector<user> allUser=db.search(searchKey);
        int rowCount=0;
        for (int i=0; i<allUser.size(); i++)
            if (!allUser[i]._new)
            {
                if (rowCount==k)
                    db.users.erase(allUser[i]._key);
                rowCount++;
            }
    }
    saveToBackup();
}
void MainWindow::deleteCustomer()
{
    if(customersWidget->currentRow()>=0)
    {
        int k=customersWidget->currentRow();
        customersWidget->removeRow(k);

        vector<string> searchKey;
        vector<user> allUser=db.search(searchKey);
        int rowCount=0;
        for (int i=0; i<allUser.size(); i++)
            if (allUser[i]._new)
            {
                if (rowCount==k)
                    db.users.erase(allUser[i]._key);
                rowCount++;
            }
    }
    saveToBackup();
}
void MainWindow::viewPopup()
{
    string search = searchInput->text().toStdString();
    string temp;
    stringstream ss(search);
    vector<string> R;
    while (ss>>temp)
    {
        cout << "search Input " << temp << endl;
        R.push_back(temp);
    }
    userR = db.search(R);
    vector<user> allUser=userR;
    int leadnum=0;
    int customernum=0;
    leadsWidget->setSortingEnabled(0);
    customersWidget->setSortingEnabled(0);
    leadsWidget->clearContents();
    for(int i=0; i<leadsWidget->rowCount(); i++)
        leadsWidget->removeRow(0);
    customersWidget->clearContents();
    for(int i=0; i<customersWidget->rowCount(); i++)
        customersWidget->removeRow(0);
    for (int i=0; i<allUser.size(); i++)
        if (!allUser[i]._new)
        {
            leadsWidget->insertRow(leadnum);
            vector<string> tempN = allUser[i]._name;
            string nameInput1 = "";
            for (unsigned int j=0; j<tempN.size(); j++)
            {
                nameInput1 = nameInput1+tempN[j]+" ";
            }
            //  cout<<nameInput1;
            QTableWidgetItem* dateItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._date));
            leadsWidget->setItem(leadnum,0, dateItem);
            cout<<"leadnum: "<<leadnum<<" "<<nameInput1<<endl;
            QTableWidgetItem* nameItem=new QTableWidgetItem(QString::fromStdString(nameInput1));
            leadsWidget->setItem(leadnum,1, nameItem);
            QTableWidgetItem* cellItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._cell));
            leadsWidget->setItem(leadnum,2, cellItem);
            QTableWidgetItem* emailItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._email));
            leadsWidget->setItem(leadnum,3, emailItem);
            QTableWidgetItem* makeItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._make));
            leadsWidget->setItem(leadnum,4, makeItem);
            QTableWidgetItem* modelItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._model));
            leadsWidget->setItem(leadnum,5, modelItem);
            QTableWidgetItem* exteriorItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._exterior));
            leadsWidget->setItem(leadnum,6, exteriorItem);
            QTableWidgetItem* interiorItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._interior));
            leadsWidget->setItem(leadnum,7, interiorItem);
            QTableWidgetItem* yearItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._year));
            leadsWidget->setItem(leadnum,8, yearItem);
            QTableWidgetItem* msrpItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._msrp));
            leadsWidget->setItem(leadnum,9, msrpItem);
            QTableWidgetItem* optionsItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._options));
            leadsWidget->setItem(leadnum,10, optionsItem);
            QTableWidgetItem* priceItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._price));
            leadsWidget->setItem(leadnum,11, priceItem);
            QTableWidgetItem* purposeItem;
            if (allUser[i]._lease)
                purposeItem=new QTableWidgetItem("lease");
            else
                purposeItem=new QTableWidgetItem("Purchase");
            leadsWidget->setItem(leadnum,12, purposeItem);
            QTableWidgetItem* orderNItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._orderNumber));
            leadsWidget->setItem(leadnum,13,orderNItem);
            leadnum++;
        }

        else	if (allUser[i]._new)
        {
            customersWidget->insertRow(customernum);
            vector<string> tempN = allUser[i]._name;
            string nameInput1 = "";
            for (unsigned int j=0; j<tempN.size(); j++)
            {
                nameInput1 = nameInput1+tempN[j]+" ";
            }
            cout<<nameInput1;
            QTableWidgetItem* dateItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._date));
            customersWidget->setItem(customernum,0, dateItem);
            QTableWidgetItem* nameItem=new QTableWidgetItem(QString::fromStdString(nameInput1));
            customersWidget->setItem(customernum,1, nameItem);
            QTableWidgetItem* cellItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._cell));
            customersWidget->setItem(customernum,2, cellItem);
            QTableWidgetItem* emailItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._email));
            customersWidget->setItem(customernum,3, emailItem);
            QTableWidgetItem* makeItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._make));
            customersWidget->setItem(customernum,4, makeItem);
            QTableWidgetItem* modelItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._model));
            customersWidget->setItem(customernum,5, modelItem);
            if (allUser[i]._lease)
            {
                QTableWidgetItem* downItem=new QTableWidgetItem(tr("%1").arg(allUser[i]._down));
                customersWidget->setItem(customernum,6, downItem);
                QTableWidgetItem* termItem=new QTableWidgetItem(tr("%1").arg(allUser[i]._term));
                customersWidget->setItem(customernum,7, termItem);
                QTableWidgetItem* milesItem=new QTableWidgetItem(tr("%1").arg(allUser[i]._miles));
                customersWidget->setItem(customernum,8, milesItem);
            }
            else
            {
                QTableWidgetItem* dotdItem=new QTableWidgetItem(tr("%1").arg(allUser[i]._dotd));
                customersWidget->setItem(customernum,9, dotdItem);
            }
            QTableWidgetItem* purposeItem;
            if (allUser[i]._lease)
                purposeItem=new QTableWidgetItem("lease");
            else
                purposeItem=new QTableWidgetItem("Purchase");
            customersWidget->setItem(customernum,10, purposeItem);
            QTableWidgetItem* orderNItem=new QTableWidgetItem(QString::fromStdString(allUser[i]._orderNumber));
            customersWidget->setItem(leadnum,11,orderNItem);
            customernum++;
        }
    leadsWidget->setSortingEnabled(true);
    customersWidget->setSortingEnabled(true);
}
void MainWindow::reminder()
{
    QDialog reminderWindow;
    QVBoxLayout* overallLayout = new QVBoxLayout();
    reminderWindow.setWindowTitle("Reminder");
    QListWidget* reminderList = new QListWidget(0);
    QLabel* tdLabel=new QLabel("Today:");
    //Need further work
    overallLayout->addWidget(tdLabel);
    overallLayout->addWidget(reminderList);


    QString presentDateQS4=QDate::currentDate().toString("yyyy.MM.dd");
    string qdate = presentDateQS4.toStdString();
    cout << db.findDate(qdate).size() << " size" << endl;
    for (unsigned int i=0; i<db.findDate(qdate).size(); i++)
    {
        string display = db.findDate(qdate)[i].displayString();
        cout << display << endl;
        reminderList->addItem(QString::fromStdString(display));
    }
    QLabel* tmrLabel=new QLabel("Tomorrow:");
    QListWidget* tmrList = new QListWidget(0);
    overallLayout->addWidget(tmrLabel);
    overallLayout->addWidget(tmrList);
    presentDateQS4=QDate::currentDate().addDays(1).toString("yyyy.MM.dd");
    qdate = presentDateQS4.toStdString();
    cout << db.findDate(qdate).size() << " size" << endl;
    for (unsigned int i=0; i<db.findDate(qdate).size(); i++)
    {
        string display = db.findDate(qdate)[i].displayString();
        cout << display << endl;
        tmrList->addItem(QString::fromStdString(display));
    }
    //reminderList->addItem("This Week:");
    QLabel* weekLabel=new QLabel("This Week:");
    QListWidget* weekList = new QListWidget(0);
    overallLayout->addWidget(weekLabel);
    overallLayout->addWidget(weekList);
    for(int i=2; i<9; i++)
    {
        presentDateQS4=QDate::currentDate().addDays(i).toString("yyyy.MM.dd");
        qdate = presentDateQS4.toStdString();
        cout << db.findDate(qdate).size() << " size" << endl;
        for (unsigned int i=0; i<db.findDate(qdate).size(); i++)
        {
            string display = db.findDate(qdate)[i].displayString();
            cout << display << endl;
            weekList->addItem(QString::fromStdString(display));
        }
    }
    QPushButton* select = new QPushButton("Select");
    connect(select, SIGNAL(clicked()), this, SLOT(editUser()));
    reminderWindow.setLayout(overallLayout);
    reminderWindow.exec();

}
void MainWindow::selectFile()
{
    std::string name = "database.txt";
    db.parse(name);
    reminder();
}
void MainWindow::newUserPopup()
{
    addTrigger1=0;
    addTrigger2=0;
    popWindow = new QDialog;
    popWindow->setWindowTitle("Add new User");
    overallLayout = new QVBoxLayout();
    inputlhs = new QFormLayout();
    QLabel* leftLabel=new QLabel("(");
    QLabel* rightLabel=new QLabel(")");
    QLabel* dashLabel=new QLabel("-");
    nameInput = new QLineEdit("");
    cellLayout=new QHBoxLayout();
    cell1=new QLineEdit("");
    cell2=new QLineEdit("");
    cell3=new QLineEdit("");
    cellLayout->addWidget(leftLabel);
    cellLayout->addWidget(cell1);
    cellLayout->addWidget(rightLabel);
    // cellLayout->addWidget(dashLabel);
    cellLayout->addWidget(cell2);
    cellLayout->addWidget(dashLabel);
    cellLayout->addWidget(cell3);
    inputlhs->addRow(tr("&Name:"),nameInput);
    orderNInput=new QLineEdit("");
    inputlhs->addRow(tr("Order Number:"),orderNInput);
    inputlhs->addRow(tr("Cell:"),cellLayout);
    email = new QLineEdit("");
    inputlhs->addRow(tr("&Email:"),email);
    makeInput = new QLineEdit("");
    inputlhs->addRow(tr("&Make:"),makeInput);
    modelInput = new QLineEdit("");
    inputlhs->addRow(tr("&Model:"),modelInput);

    purpose = new QComboBox();
    QLabel* purposeLabel = new QLabel("Purpose:");
    purpose->addItem("");
    purpose->addItem("Purchasing");
    purpose->addItem("Leasing");
    //int index;
    connect(purpose, SIGNAL(currentIndexChanged(int)), this, SLOT(popUpModifier(int)));
    QLabel* callDate = new QLabel("Select CallBack Date:");
    editC = new QCalendarWidget;
    editC->setGridVisible(true);
    //QLabel* Comment = new QLabel("Comments:");
    commentInput = new QTextEdit();
    overallLayout->addLayout(inputlhs);
    overallLayout->addWidget(purposeLabel);
    overallLayout->addWidget(purpose);
    overallLayout->addWidget(callDate);
    overallLayout->addWidget(editC);
    //overallLayout->addWidget(Comment);
    //overallLayout->addWidget(commentInput);
    QPushButton* saveButton = new QPushButton("Save");
    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveInput2()));
    overallLayout->addWidget(saveButton);
    popWindow->setLayout(overallLayout);
    popWindow->exec();
}
void MainWindow::popUpModifier(int index)
{

    if ((index==1)&&(!addTrigger1))
    {   dotdInput = new QLineEdit("");
        inputlhs->addRow(tr("Dotd:"),dotdInput);
        addTrigger1=1;
    }
    else if (!addTrigger2)
    {
        downInput = new QLineEdit("");
        inputlhs->addRow(tr("DownPayment:"),downInput);
        termInput = new QLineEdit("");
        inputlhs->addRow(tr("Term:"),termInput);
        milesInput = new QLineEdit("");
        inputlhs->addRow(tr("Miles/Year:"),milesInput);
        addTrigger2=1;
    }
    // addTrigger=1;
    popWindow->exec();
}
void MainWindow::popUpModifier2(int index)
{

    if ((index==1)&&(!addTrigger1))
    {   dotdInput = new QLineEdit("");
        inputlhs->addRow(tr("Dotd:"),dotdInput);
        addTrigger1=1;
    }
    else if (!addTrigger2)
    {
        downInput = new QLineEdit("");
        inputlhs->addRow(tr("DownPayment:"),downInput);
        termInput = new QLineEdit("");
        inputlhs->addRow(tr("Term:"),termInput);
        milesInput = new QLineEdit("");
        inputlhs->addRow(tr("Miles/Year:"),milesInput);
        addTrigger2=1;
    }
    // addTrigger=1;
    popWindow->exec();
}
void MainWindow::saveInput2()

{
	addTrigger1=0;
    addTrigger2=0;
    if(purpose->currentIndex()>0)
    {
        QDate presentDate=QDate::currentDate();
        QString presentDateQS=presentDate.toString("yyyy.MM.dd");
        string presentDateS=presentDateQS.toStdString();
        string nameS = nameInput->text().toStdString();
        for(int i=0; i<(int)nameS.size(); i++)
            if (nameS[i]==' ') nameS[i]='*';
        string cellS = cell1->text().toStdString()+cell2->text().toStdString()+cell3->text().toStdString();
        string emailS = email->text().toStdString();
        //int purposeS=purpose->currentIndex();
        string make=makeInput->text().toStdString();
        string model=modelInput->text().toStdString();
        string orderN=orderNInput->text().toStdString();
        user newUser(nameS,presentDateS,cellS);
        newUser._orderNumber=orderN;
        newUser._email=emailS;
        newUser._make=make;
        newUser._model=model;
        if (purpose->currentIndex()==1)
        {
            newUser._dotd=atoi(dotdInput->text().toStdString().c_str());
        }
        else if  (purpose->currentIndex()==2)
        {
            newUser._down=atoi(downInput->text().toStdString().c_str());
            newUser._term=atoi(termInput->text().toStdString().c_str());
            newUser._miles=atoi(milesInput->text().toStdString().c_str());
        }
        newUser._new=1;
        newUser._lease=purpose->currentIndex()-1;
        //newUser._callHistory.push_back(callH);
        //newUser._callHistoryNum=newUser._callHistory.size();
        QDate selectedDate2 = editC->selectedDate();
        QString selectedDateQS2 = selectedDate2.toString("yyyy.MM.dd");
        string selectedDateS2 = selectedDateQS2.toStdString();
//cout<<selectedDateS2<<endl;
        newUser._callBackDate=selectedDateS2;
        db.addUser(newUser);
        viewPopup();
        saveSuccess();
    }
}

void MainWindow::editUser()
{
    popWindows = new QDialog();
    popWindows->setWindowTitle("Edit User");
    if(leadsWidget->currentRow()>=0)
    {
        int k=leadsWidget->currentRow();
        leadsWidget->removeRow(k);

        vector<string> searchKey;
        vector<user> allUser=db.search(searchKey);
        int rowCount=0;
        for (int i=0; i<allUser.size(); i++)
            if (!allUser[i]._new)
            {
                if (rowCount==k)
                {    user temp =allUser[i];
                vector<string> tempN = temp._name;
                string nameInput1 = "";
                for (unsigned int j=0; j<tempN.size(); j++)
                {
                    nameInput1 = nameInput1+" "+tempN[j];
                }
                nameInput= new QLineEdit(QString::fromStdString(nameInput1));
                popWindow = new QDialog;
                popWindow->setWindowTitle("Add new Lead");
                QVBoxLayout* overallLayout = new QVBoxLayout();
                QFormLayout* inputlhs = new QFormLayout();
                QLabel* leftLabel=new QLabel("(");
                QLabel* rightLabel=new QLabel(")");
                QLabel* dashLabel=new QLabel("-");
                nameInput = new QLineEdit(QString::fromStdString(nameInput1));
                cellLayout=new QHBoxLayout();
                if(temp._cell.size()>=3)
                cell1=new QLineEdit(QString::fromStdString(temp._cell.substr(0,3)));
            else cell1=new QLineEdit("");
          		  if(temp._cell.size()>=6)
                cell2=new QLineEdit(QString::fromStdString(temp._cell.substr(3,3)));
            else cell2=new QLineEdit("");
                if(temp._cell.size()>=10)
                cell3=new QLineEdit(QString::fromStdString(temp._cell.substr(6,4)));
            else cell3=new QLineEdit("");
                cellLayout->addWidget(leftLabel);
                cellLayout->addWidget(cell1);
                cellLayout->addWidget(rightLabel);
                // cellLayout->addWidget(dashLabel);
                cellLayout->addWidget(cell2);
                cellLayout->addWidget(dashLabel);
                cellLayout->addWidget(cell3);
                inputlhs->addRow(tr("&Name:"),nameInput);
                orderNInput=new QLineEdit(QString::fromStdString(temp._orderNumber));
                inputlhs->addRow(tr("Order Number:"),orderNInput);
                inputlhs->addRow(tr("Cell:"),cellLayout);
                email = new QLineEdit(QString::fromStdString(temp._email));
                inputlhs->addRow(tr("&Email:"),email);
                makeInput = new QLineEdit(QString::fromStdString(temp._make));
                inputlhs->addRow(tr("&Make:"),makeInput);
                modelInput = new QLineEdit(QString::fromStdString(temp._model));
                inputlhs->addRow(tr("&Model:"),modelInput);
                colorInput2 = new QLineEdit(QString::fromStdString(temp._exterior));
                inputlhs->addRow(tr("&Exterior Color:"),colorInput2);
                colorInput = new QLineEdit(QString::fromStdString(temp._interior));
                inputlhs->addRow(tr("&Interior Color:"),colorInput);
                yearInput = new QLineEdit(QString::fromStdString(temp._year));
                inputlhs->addRow(tr("&Year:"),yearInput);
                msrpInput = new QLineEdit(QString::fromStdString(temp._msrp));
                inputlhs->addRow(tr("&MSRP:"),msrpInput);
                optionsInput = new QLineEdit(QString::fromStdString(temp._options));
                inputlhs->addRow(tr("&options:"),optionsInput);
                priceInput = new QLineEdit(QString::fromStdString(temp._price));
                inputlhs->addRow(tr("&PriceQuoted:"),priceInput);
                overallLayout->addLayout(inputlhs);
                purpose = new QComboBox();
                QLabel* purposeLabel = new QLabel("Purpose:");
                purpose->addItem("Purchasing");
                purpose->addItem("Leasing");
                QLabel* callDate = new QLabel("Select CallBack Date:");
                editC = new QCalendarWidget;
                editC->setGridVisible(true);
                //QLabel* Comment = new QLabel("Comments:");
                commentInput = new QTextEdit();
                overallLayout->addWidget(purposeLabel);
                overallLayout->addWidget(purpose);
                overallLayout->addWidget(callDate);
                overallLayout->addWidget(editC);
                //overallLayout->addWidget(Comment);
                //overallLayout->addWidget(commentInput);
                rowCount++;
                 db.users.erase(allUser[i]._key);
                QPushButton* saveButton = new QPushButton("Save");
                connect(saveButton, SIGNAL(clicked()), this, SLOT(saveInput()));
                overallLayout->addWidget(saveButton);
                popWindow->setLayout(overallLayout);
                popWindow->exec();
            }
            }
    }
}
void MainWindow::editCustomer()
{
    popWindows = new QDialog();
    popWindows->setWindowTitle("Edit User");
    if(customersWidget->currentRow()>=0)
    {
        int k=customersWidget->currentRow();
        customersWidget->removeRow(k);

        vector<string> searchKey;
        vector<user> allUser=db.search(searchKey);
        int rowCount=0;
        for (int i=0; i<allUser.size(); i++)
            if (allUser[i]._new)
            {
                if (rowCount==k)
                {    user temp =allUser[i];
                vector<string> tempN = temp._name;
                string nameInput1 = "";
                for (unsigned int j=0; j<tempN.size(); j++)
                {
                    nameInput1 = nameInput1+" "+tempN[j];
                }
                nameInput= new QLineEdit(QString::fromStdString(nameInput1));
                popWindow = new QDialog;
                popWindow->setWindowTitle("Add new Lead");
                QVBoxLayout* overallLayout = new QVBoxLayout();
                QFormLayout* inputlhs = new QFormLayout();
                QLabel* leftLabel=new QLabel("(");
                QLabel* rightLabel=new QLabel(")");
                QLabel* dashLabel=new QLabel("-");
                nameInput = new QLineEdit(QString::fromStdString(nameInput1));
                cellLayout=new QHBoxLayout();
                if(temp._cell.size()>=3)
                cell1=new QLineEdit(QString::fromStdString(temp._cell.substr(0,3)));
            else cell1=new QLineEdit("");
          		  if(temp._cell.size()>=6)
                cell2=new QLineEdit(QString::fromStdString(temp._cell.substr(3,3)));
            else cell2=new QLineEdit("");
                if(temp._cell.size()>=10)
                cell3=new QLineEdit(QString::fromStdString(temp._cell.substr(6,4)));
            else cell3=new QLineEdit("");
                cellLayout->addWidget(leftLabel);
                cellLayout->addWidget(cell1);
                cellLayout->addWidget(rightLabel);
                // cellLayout->addWidget(dashLabel);
                cellLayout->addWidget(cell2);
                cellLayout->addWidget(dashLabel);
                cellLayout->addWidget(cell3);
                inputlhs->addRow(tr("&Name:"),nameInput);
                orderNInput=new QLineEdit(QString::fromStdString(temp._orderNumber));
                inputlhs->addRow(tr("Order Number:"),orderNInput);
                inputlhs->addRow(tr("Cell:"),cellLayout);
                email = new QLineEdit(QString::fromStdString(temp._email));
                inputlhs->addRow(tr("&Email:"),email);
                makeInput = new QLineEdit(QString::fromStdString(temp._make));
                inputlhs->addRow(tr("&Make:"),makeInput);
                modelInput = new QLineEdit(QString::fromStdString(temp._model));
                inputlhs->addRow(tr("&Model:"),modelInput);
                colorInput2 = new QLineEdit(QString::fromStdString(temp._exterior));
                 purpose = new QComboBox();
    			QLabel* purposeLabel = new QLabel("Purpose:");
    			purpose->addItem("");
    			purpose->addItem("Purchasing");
    			purpose->addItem("Leasing");
    //int index;
    connect(purpose, SIGNAL(currentIndexChanged(int)), this, SLOT(popUpModifier2(int)));
    QLabel* callDate = new QLabel("Select CallBack Date:");
    editC = new QCalendarWidget;
    editC->setGridVisible(true);
    //QLabel* Comment = new QLabel("Comments:");
    commentInput = new QTextEdit();
    overallLayout->addLayout(inputlhs);
    overallLayout->addWidget(purposeLabel);
    overallLayout->addWidget(purpose);
    overallLayout->addWidget(callDate);
    overallLayout->addWidget(editC);
    //overallLayout->addWidget(Comment);
    //overallLayout->addWidget(commentInput);
    QPushButton* saveButton = new QPushButton("Save");
    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveInput2()));
    overallLayout->addWidget(saveButton);
    popWindow->setLayout(overallLayout);
    popWindow->exec();
                //overallLayout->addWidget(Comment);
                //overallLayout->addWidget(commentInput);
                rowCount++;
               
            }
            }
    }
}
/*void MainWindow::uploadP()
{
	QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"),"Home://","PNG files(*.png);;JPG files(*.jpg)");
	showAddress->addItem(fileName);
	_keepImages.push_back(fileName);
	QImage* newImage = new QImage();
	newImage->load(fileName);
	addressKeep.push_back(newImage);
	cout << "upload success " << endl;
	saveToBackup();
}*/


//save to file window
void MainWindow::exportPopup()
{
    string name = "database.txt";
    ofstream of(name.c_str());
    db.dump(of);
    of.close();
}
//function of ofile
void MainWindow::ofile()
{
    save->close();
}
void MainWindow::showPopup()
{
    popWindow = new QDialog;
    popWindow->setWindowTitle("Add new Lead");
    QVBoxLayout* overallLayout = new QVBoxLayout();
    QFormLayout* inputlhs = new QFormLayout();
    QLabel* leftLabel=new QLabel("(");
    QLabel* rightLabel=new QLabel(")");
    QLabel* dashLabel=new QLabel("-");
    nameInput = new QLineEdit("");
    cellLayout=new QHBoxLayout();
    cell1=new QLineEdit("");
    cell2=new QLineEdit("");
    cell3=new QLineEdit("");
    cellLayout->addWidget(leftLabel);
    cellLayout->addWidget(cell1);
    cellLayout->addWidget(rightLabel);
    // cellLayout->addWidget(dashLabel);
    cellLayout->addWidget(cell2);
    cellLayout->addWidget(dashLabel);
    cellLayout->addWidget(cell3);
    inputlhs->addRow(tr("&Name:"),nameInput);
    orderNInput=new QLineEdit("");
    inputlhs->addRow(tr("Order Number:"),orderNInput);
    cellInput = new QLineEdit("");
    inputlhs->addRow(tr("Cell:"),cellLayout);
    email = new QLineEdit("");
    inputlhs->addRow(tr("&Email:"),email);
    makeInput = new QLineEdit("");
    inputlhs->addRow(tr("&Make:"),makeInput);
    modelInput = new QLineEdit("");
    inputlhs->addRow(tr("&Model:"),modelInput);
    colorInput2 = new QLineEdit("");
    inputlhs->addRow(tr("&Exterior Color:"),colorInput2);
    colorInput = new QLineEdit("");
    inputlhs->addRow(tr("&Interior Color:"),colorInput);
    yearInput = new QLineEdit("");
    inputlhs->addRow(tr("&Year:"),yearInput);
    msrpInput = new QLineEdit("");
    inputlhs->addRow(tr("&MSRP:"),msrpInput);
    optionsInput = new QLineEdit("");
    inputlhs->addRow(tr("&options:"),optionsInput);
    priceInput = new QLineEdit("");
    inputlhs->addRow(tr("&PriceQuoted:"),priceInput);
    overallLayout->addLayout(inputlhs);
    purpose = new QComboBox();
    QLabel* purposeLabel = new QLabel("Purpose:");
    purpose->addItem("Purchasing");
    purpose->addItem("Leasing");
    QLabel* callDate = new QLabel("Select CallBack Date:");
    editC = new QCalendarWidget;
    editC->setGridVisible(true);
    //QLabel* Comment = new QLabel("Comments:");
    commentInput = new QTextEdit();
    overallLayout->addWidget(purposeLabel);
    overallLayout->addWidget(purpose);
    overallLayout->addWidget(callDate);
    overallLayout->addWidget(editC);
    //overallLayout->addWidget(Comment);
    //overallLayout->addWidget(commentInput);
    QPushButton* saveButton = new QPushButton("Save");
    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveInput()));
    overallLayout->addWidget(saveButton);
    popWindow->setLayout(overallLayout);
    popWindow->exec();
}

void MainWindow::saveInput()
{   QDate presentDate=QDate::currentDate();
    QString presentDateQS=presentDate.toString("yyyy.MM.dd");
    string presentDateS=presentDateQS.toStdString();
    string nameS = nameInput->text().toStdString();
    for(int i=0; i<(int)nameS.size(); i++)
        if (nameS[i]==' ') nameS[i]='*';
    string cellS = cell1->text().toStdString()+cell2->text().toStdString()+cell3->text().toStdString();
    string emailS = email->text().toStdString();
    //int purposeS=purpose->currentIndex();
    string make=makeInput->text().toStdString();
    string model=modelInput->text().toStdString();
    string exterior=colorInput2->text().toStdString();
    string interior=colorInput->text().toStdString();
    string year=yearInput->text().toStdString();
    string msrp=msrpInput->text().toStdString();
    string options=optionsInput->text().toStdString();
    string price=priceInput->text().toStdString();
    string orderN=orderNInput->text().toStdString();
    user newUser(nameS,presentDateS,cellS);
    newUser._orderNumber=orderN;
    newUser._email=emailS;
    newUser._make=make;
    newUser._model=model;
    newUser._exterior=exterior;
    newUser._interior=interior;
    newUser._year=year;
    newUser._msrp=msrp;
    newUser._options=options;
    newUser._price=price;

    newUser._new=0;
    newUser._lease=purpose->currentIndex();
    QDate selectedDate2 = editC->selectedDate();
    QString selectedDateQS2 = selectedDate2.toString("yyyy.MM.dd");
    string selectedDateS2 = selectedDateQS2.toStdString();
//cout<<selectedDateS2<<endl;
    newUser._callBackDate=selectedDateS2;
    //newUser._callHistory.push_back(callH);
    //newUser._callHistoryNum=newUser._callHistory.size();
    db.addUser(newUser);
    viewPopup();
    saveSuccess();
}
void MainWindow::saveSuccess()
{
    popWindow->close();
    QMessageBox* msgBox = new QMessageBox;
    msgBox->setWindowTitle("Success");
    msgBox->setText("Your input has been successfully saved!");
    msgBox->setStandardButtons(QMessageBox::Cancel);
    msgBox->exec();
    saveToBackup();
}
void MainWindow::saveToBackup()
{
    ofstream of("database.txt");
    db.dump(of);
    of.close();
}

/*void MainWindow::choice()
{
	if (searchFile->isChecked())
	{
		searchPopup();
	}
	else if (inputFile->isChecked())
	{
		showPopup();
	}
	else if (exportFile->isChecked())
	{
		exportPopup();
	}
	else if (viewPlan->isChecked())
	{
		planPopup();
	}
}*/
/*void MainWindow::planPopup()
{
	QDialog planWindow;
	QVBoxLayout* overallLayout = new QVBoxLayout;
	//QCalendarWidget*
	 planC = new QCalendarWidget;
	overallLayout->addWidget(planC);
	planC->setGridVisible(true);
	//selectedDate = planC->selectedDate();
	selectedDateQS = selectedDate.toString("yyyy.MM.dd");
	connect(planC,SIGNAL(selectionChanged()),this,SLOT(setToDate()));
	QPushButton* selectD = new QPushButton("Select date");
	connect(selectD, SIGNAL(clicked()), this, SLOT(viewSpecific()));
	QPushButton* viewMonth=new QPushButton("view Month");
	connect(viewMonth,SIGNAL(clicked()),this,SLOT(viewMonth()));
	overallLayout->addWidget(selectD);
	overallLayout->addWidget(viewMonth);
	planWindow.setLayout(overallLayout);
	planWindow.exec();
	saveToBackup();
}
void MainWindow::setToDate()
{
	selectedDate=planC->selectedDate();
}
void MainWindow::viewMonth()
{
	QDialog specific;
	QVBoxLayout* overallLayout = new QVBoxLayout;
	QListWidget* listSpecific = new QListWidget;
	int month=selectedDate.month();
	int year=selectedDate.year();
	int days=selectedDate.daysInMonth();
	for(int i=0;i<days;i++)
	{
		QDate newDate(year,month,i);
	//selectedDate = planC->slectedDate();
	QString presentDateQS4=newDate.toString("yyyy.MM.dd");
	string qdate = presentDateQS4.toStdString();
	cout << "qdate " << qdate << endl;
	cout << db.findDate(qdate).size() << " size" << endl;
	for (unsigned int i=0; i<db.findDate(qdate).size(); i++)
	{
		string display = db.findDate(qdate)[i].displayString();
		cout << display << endl;
		listSpecific->addItem(QString::fromStdString(display));
	}
	}
	overallLayout->addWidget(listSpecific);
	specific.setLayout(overallLayout);
	specific.exec();
	saveToBackup();
}
void MainWindow::viewSpecific()
{
	QDialog specific;
	QVBoxLayout* overallLayout = new QVBoxLayout;
	QListWidget* listSpecific = new QListWidget;
	//selectedDate = planC->selectedDate();
	QString presentDateQS4=selectedDate.toString("yyyy.MM.dd");
	string qdate = presentDateQS4.toStdString();
	cout << "qdate " << qdate << endl;
	cout << db.findDate(qdate).size() << " size" << endl;
	for (unsigned int i=0; i<db.findDate(qdate).size(); i++)
	{
		string display = db.findDate(qdate)[i].displayString();
		cout << display << endl;
		listSpecific->addItem(QString::fromStdString(display));
	}
	overallLayout->addWidget(listSpecific);
	specific.setLayout(overallLayout);
	specific.exec();
	saveToBackup();
}
//view profile, search, call history
void MainWindow::searchPopup()
{
	QDialog viewWindow;
	lhsLayout = new QVBoxLayout;
	search = new QLabel("Search customer profile:");
	lhsLayout->addWidget(search);
	searchInput = new QLineEdit();
	lhsLayout->addWidget(searchInput);
	viewFile = new QPushButton("Search");
	connect(viewFile, SIGNAL(clicked()), this, SLOT(viewPopup()));


	listLayout = new QGridLayout;

	list = new QComboBox();
	listLabel = new QLabel("Choose list order:");
	listLayout->addWidget(listLabel);

	//Choose the way of listing
	list->addItem("alphabetical sort");
	list->addItem("date sort");
	listLayout->addWidget(listLabel, 1, 0, 1, 1);
	listLayout->addWidget(list, 2, 0, 1, 2);
	listLayout->addWidget(viewFile);
	//listLayout->addWidget(list);
	lhsLayout->addLayout(listLayout);
	profileListWidget = new QListWidget();
	//connect(profileWidget,SIGNAL(currentRowChanged(int)), this, SLOT(displayReview(int)));
	lhsLayout->addWidget(profileListWidget);

	searchButtons = new QGridLayout;
	callButton = new QPushButton("Call History");
	connect(callButton, SIGNAL(clicked()), this, SLOT(callHistory()));
	editButton = new QPushButton("Edit User");
	connect(editButton, SIGNAL(clicked()), this, SLOT(editUser()));
	searchButtons->addWidget(callButton, 1, 0, 1, 1);
	searchButtons->addWidget(editButton, 1, 2, 1, 1);

	//TODO
	//add calendar whenever call history || add history
	lhsLayout->addLayout(searchButtons);
	viewWindow.setLayout(lhsLayout);
	viewWindow.exec();
}
/*void MainWindow::callHistory()
{
	historyWindow = new QDialog;
	QVBoxLayout* overallLayout = new QVBoxLayout;
	listHistory = new QListWidget;
	overallLayout->addWidget(listHistory);
	historyWindow->setWindowTitle("View Call History");
	if (profileListWidget->currentRow()<0)
		return;
	user temp = userR[profileListWidget->currentRow()];
	vector<string> u = temp._name;
	string userName="";
	for (unsigned int i=0; i<u.size();i++)
	{
		userName=userName+" "+u[i];

	//QLabel* title = new QLabel(userName);
	}
	QString quser = QString::fromStdString(userName);
	listHistory->addItem(quser);

	for (unsigned int i=0; i<temp._callHistory.size(); i++)
	{
		string chDate = temp._callHistory[i]._date;
		QString qchDate = QString::fromStdString(chDate);
		listHistory->addItem(qchDate);
	}
	QHBoxLayout* buttons = new QHBoxLayout;
	QPushButton* addCall = new QPushButton("Add Call");
	connect(addCall, SIGNAL(clicked()), this, SLOT(addCallPopup()));
	QPushButton* details = new QPushButton("View Details");
	connect(details, SIGNAL(clicked()), this, SLOT(detailsPopup()));
	QPushButton* cancel = new QPushButton("Cancel");
	connect(cancel, SIGNAL(clicked()), this, SLOT(cancelCHPopup()));
	buttons->addWidget(details);
	buttons->addWidget(addCall);
	buttons->addWidget(cancel);
	overallLayout->addLayout(buttons);
	historyWindow->setLayout(overallLayout);
	historyWindow->exec();
	saveToBackup();
}*/
/*void MainWindow::addCallPopup()
{
	addCallWindow = new QDialog();
	QVBoxLayout* overallLayout = new QVBoxLayout;
	QFormLayout* addCallForm = new QFormLayout();
	makeInputC = new QLineEdit("");
	addCallForm->addRow(tr("&Make:"),makeInputC);
	colorInput2C = new QLineEdit("");
	addCallForm->addRow(tr("&Exterior Color:"),colorInput2C);
	colorInputC = new QLineEdit("");
	addCallForm->addRow(tr("&Interior Color:"),colorInputC);
	yearInputC = new QLineEdit("");
	addCallForm->addRow(tr("&Year:"),yearInputC);
	mrspC = new QLineEdit("");
	addCallForm->addRow(tr("&M.R.S.P:"),mrspC);
	valueInputC = new QLineEdit("");
	addCallForm->addRow(tr("&Current Value:"),valueInputC);
	navigationC = new QLineEdit("");
	addCallForm->addRow(tr("&Navigation:"),navigationC);
	RCameraC = new QLineEdit("");
	addCallForm->addRow(tr("&Rear Camera:"),RCameraC);
	featureInputC = new QLineEdit("");
	addCallForm->addRow(tr("&Additional Features:"),featureInputC);
	QVBoxLayout* additionalLayout = new QVBoxLayout;
	QLabel* additionC = new QLabel("Additional Information:");
	additionalLayout->addWidget(additionC);
	purposeC = new QComboBox();
	QLabel* purposeLabelC = new QLabel("Purpose of Calling:");
	additionalLayout->addWidget(purposeLabelC);
	additionalLayout->addWidget(purposeC);
	purposeC->addItem("Purchasing");
	purposeC->addItem("Leasing");
	QLabel* callDateC = new QLabel("Select Date:");
	editCC = new QCalendarWidget;
	editCC->setGridVisible(true);
	additionalLayout->addWidget(callDateC);
	additionalLayout->addWidget(editCC);
	QLabel* Comment = new QLabel("Comments:");
	commentInput = new QTextEdit();
	additionalLayout->addWidget(Comment);
	additionalLayout->addWidget(commentInput);
	QPushButton* saveD = new QPushButton("Save");
	additionalLayout->addWidget(saveD);
	connect(saveD, SIGNAL(clicked()), this, SLOT(saveDPopup()));;
	overallLayout->addLayout(addCallForm);
	overallLayout->addLayout(additionalLayout);
	addCallWindow->setLayout(overallLayout);
	addCallWindow->exec();
	saveToBackup();
}*/
/*void MainWindow::saveDPopup()
{
	string makeSD = makeInputC->text().toStdString();
	string color1SD = colorInput2C->text().toStdString();
	string color2SD = colorInputC->text().toStdString();
	string yearSD = yearInputC->text().toStdString();
	string mrspSD = mrspC->text().toStdString();
	string valueInputSD = valueInputC->text().toStdString();
	string navigationSD = navigationC->text().toStdString();
	string CameraSD = RCameraC->text().toStdString();
	string featureSD = featureInputC->text().toStdString();
	string purposeSD;
	if (purposeC->currentIndex() == 0)
	{
		purposeSD = "Purchasing";
	}
	else if (purposeC->currentIndex() == 1)
	{
		purposeSD = "Leasing";
	}
	string commentSD = commentInput->toPlainText().toStdString();
	QDate selectedDate2D = editCC->selectedDate();
	QString selectedDateQS2D = selectedDate2D.toString("yyyy.MM.dd");
	string selectedDateSD = selectedDateQS2D.toStdString();

	user* temp = &userR[profileListWidget->currentRow()];
	car addCar(makeSD,color1SD,color2SD,yearSD);
	addCar._MRSP=mrspSD;
	addCar._value=valueInputSD;
	addCar._navigation=navigationSD;
	addCar._rearCamera=CameraSD;
	addCar._feature=featureSD;
	//add call history
	for (int i=0;i<(int)commentSD.size();i++)
		if (commentSD[i]==' ')
			commentSD[i]='*';
	addCar.check();
	temp->generateCallHistory(selectedDateSD,addCar,purposeSD,commentSD);

		listHistory->addItem(selectedDateQS2D);
	db.users[temp->_key]=*temp;
	//newUser._callHistory.push_back(callH);
	//newUser._callHistoryNum=newUser._callHistory.size();
	successmsg();
}
void MainWindow::successmsg()
{
	addCallWindow->close();
	QMessageBox* msgBox = new QMessageBox;
	msgBox->setWindowTitle("Success");
	msgBox->setText("Your input has been successfully saved!");
	msgBox->setStandardButtons(QMessageBox::Cancel);
	msgBox->exec();
	saveToBackup();
}
void MainWindow::cancelCHPopup()
{
	historyWindow->close();
}
/*void MainWindow::detailsPopup()
{
	window = new QDialog;
	window->setWindowTitle("View Details");
	QVBoxLayout* overallLayout = new QVBoxLayout;
	if (listHistory->currentRow()<0)
		return;
	QListWidget* show = new QListWidget;
	int index = listHistory->currentRow()-1;
	user temp = userR[profileListWidget->currentRow()];
	string output ;
	if((index>=0)&&(index<(int)temp._callHistory.size()))
		 output = temp._callHistory[index].displayString();
	else output="";
	QString qoutput = QString::fromStdString(output);
	show->addItem(qoutput);
	QPushButton* cancel = new QPushButton("Cancel");
	connect(cancel, SIGNAL(clicked()), this, SLOT(cancelPopup()));
	overallLayout->addWidget(show);
	overallLayout->addWidget(cancel);
	window->setLayout(overallLayout);
	window->exec();
	saveToBackup();
}*/
/*void MainWindow::seeDetails(int index)
{
	if (index<0)
		return;
	cout << "see details " << endl;
	QDialog* detailFile = new QDialog();
	detailFile->setWindowTitle("See Details..");
	QVBoxLayout* overallLayout = new QVBoxLayout;
	if (showAddress->currentRow()<0)
		return;
	fileContainer = new QLabel();
	overallLayout->addWidget(fileContainer);
	cout << "index " << index << endl;
	fileContainer->setPixmap(QPixmap::fromImage(*addressKeep[index]));
	detailFile->setLayout(overallLayout);

	detailFile->exec();

}*/
/*void MainWindow::changeSave()
{
	string nameS = nameInput->text().toStdString();
	for(int i=0;i<(int)nameS.size();i++)
		if (nameS[i]==' ') nameS[i]='*';
	string cellS = cellInput->text().toStdString();
	string cell2S = cellInput2->text().toStdString();
	string emailS = email->text().toStdString();
	string addressInputS = addressInput->text().toStdString();
	for(int i=0;i<(int)addressInputS.size();i++)
		if (addressInputS[i]==' ') addressInputS[i]='*';
	string referralS = referralInput->text().toStdString();
	string brokerS = brokerInput->text().toStdString();
	string ssnS = ssnInput->text().toStdString();
	string incomeS = income->text().toStdString();
	string dobS = dob->text().toStdString();
	string officeS = officeInput->text().toStdString();
	//ethnicity = new QComboBox();
	//string ethnicityS=ethnicityQLineEdit->text().toStdString();
	/*if (ethnicity->currentIndex() == 0)
	{
		ethnicityS = "Asian";
	}
	else if (ethnicity->currentIndex() == 1)
	{
		ethnicityS = "AmericanIndianorAlaskaNative";
	}
	else if (ethnicity->currentIndex() == 2)
	{
		ethnicityS = "BlackorAfricanAmerican";
	}
	else if (ethnicity->currentIndex() == 3)
	{
		ethnicityS = "NativeHawaiianorOtherPacificIslander";
	}
	else if (ethnicity->currentIndex() == 4)
	{
		ethnicityS = "White";
	}*/
//string genderS=genderQLineEdit->text().toStdString();
/*if (gender->currentIndex() == 0)
{
	genderS = "Male";
}
else if (gender->currentIndex() == 1)
{
	genderS = "Female";
}*/
/*
cout << "ohhh lala" << endl;
string occupationS = occupation->text().toStdString();
string makeS = makeInput->text().toStdString();
string color1S = colorInput2->text().toStdString();
string color2S = colorInput->text().toStdString();
string yearS = yearInput->text().toStdString();
string mrspS = mrsp->text().toStdString();
string valueInputS = valueInput->text().toStdString();
string navigationS = navigation->text().toStdString();
string CameraS = RCamera->text().toStdString();
string featureS = featureInput->text().toStdString();

user temp =db.users[saveKey];
cout<<temp.displayString()<<endl;

temp._cell = cellS;
temp._other = cell2S;
int lastloc=0;
temp._address.clear();
for(int i=0;i<(int)addressInputS.size();i++)
{
if (addressInputS[i]=='*')
{
	temp._address.push_back(addressInputS.substr(lastloc,i-lastloc));

	lastloc=i+1;

}
}
temp._address.push_back(addressInputS.substr(lastloc,addressInputS.size()-lastloc));
cout << "after address " << endl;
QDate selectedDate2 = editC->selectedDate();
QString selectedDateQS2 = selectedDate2.toString("yyyy.MM.dd");
string selectedDateS2 = selectedDateQS2.toStdString();
//cout<<selectedDateS2<<endl;
temp._callBackDate=selectedDateS2;

temp._email=emailS;
temp._Referral=referralS;
temp._Broker=brokerS;
temp._Office=officeS;
temp._SSN=ssnS;
temp._MonthlyIncome=incomeS;
temp._DOB=dobS;
//temp._Ethnicity=ethnicityS;
//temp._Gender=genderS;
temp._Occupation=occupationS;
db.users[saveKey]=temp;
//db.replaceUser(temp);
changeSuccess();
}
void MainWindow::changeSuccess()
{
popWindows->close();
QMessageBox* msgBox = new QMessageBox;
msgBox->setWindowTitle("Success");
msgBox->setText("Your change has been successfully saved!");
msgBox->setStandardButtons(QMessageBox::Cancel);
msgBox->exec();
saveToBackup();
}*/