#include "main_window.h"
#include "dbase/dbase.h"
#include "globals.h"
#include "dbase/user.h"
#include "dbase/car.h"
#include "dbase/callHistory.h"
#include <sstream>
#include <iostream>

using namespace std;
dbase db;
MainWindow::MainWindow()
{

	
	// Title
	setWindowTitle("Welcome to Autobroker Database!");
	/*overallLayout = new QHBoxLayout;
	lhsLayout = new QVBoxLayout;
	
	search = new QLabel("Search customer profile:");
	lhsLayout->addWidget(search);
	searchInput = new QLineEdit();
	lhsLayout->addWidget(searchInput);
	viewFile = new QPushButton("Search");
	connect(viewFile, SIGNAL(clicked()), this, SLOT(viewPopup()));
	lhsLayout->addWidget(viewFile);
	overallLayout->addLayout(lhsLayout);*/
	buttonLayout = new QVBoxLayout;
	inputData = new QPushButton("Select the Database");
	connect(inputData, SIGNAL(clicked()), this, SLOT(selectFile()));
	buttonLayout->addWidget(inputData);
	select = new QLabel("Please select from the following:") ;
	buttonLayout->addWidget(select);
	searchFile = new QRadioButton("Search existing profile");
	inputFile = new QRadioButton("Input new profile");
	exportFile = new QRadioButton("Output to file");
	ok1Button = new QPushButton("OK");
	connect(ok1Button, SIGNAL(clicked()), this, SLOT(choice()));

	buttonLayout->addWidget(select);

	buttonLayout->addWidget(searchFile);
	buttonLayout->addWidget(inputFile);
	buttonLayout->addWidget(exportFile);
	buttonLayout->addWidget(ok1Button);
	setLayout(buttonLayout);
}

MainWindow::~MainWindow()
{
	
}


void MainWindow::selectFile()
{
	QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"),"Home://","All files (*.*);;Text File(*.txt)");
	QMessageBox::information(this,tr("File name"),fileName);
	std::string name = fileName.QString::toStdString();
	db.parse(name);
}

void MainWindow::choice()
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
	lhsLayout->addWidget(viewFile);

	listLayout = new QGridLayout;
	ok1 = new QPushButton("OK");
	list = new QComboBox();
	listLabel = new QLabel("Choose list order:");
	listLayout->addWidget(listLabel);
	
	//Choose the way of listing
	list->addItem("alphabetical sort");
	list->addItem("date sort");
	listLayout->addWidget(listLabel, 1, 0, 1, 1);
	listLayout->addWidget(list, 2, 0, 1, 2);
	listLayout->addWidget(ok1, 2, 2, 1, 1);
	listLayout->addWidget(list);
	lhsLayout->addLayout(listLayout);
	profileListWidget = new QListWidget();
	//connect(profileWidget,SIGNAL(currentRowChanged(int)), this, SLOT(displayReview(int)));
	lhsLayout->addWidget(profileListWidget);

	searchButtons = new QGridLayout;
	callButton = new QPushButton("Call History");
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


void MainWindow::editUser()
{
	QDialog popWindow;
	popWindow.setWindowTitle("Edit User");
	QVBoxLayout* overallLayout = new QVBoxLayout();
	QHBoxLayout* inputLayout = new QHBoxLayout();
	QHBoxLayout* labelLayout = new QHBoxLayout();
	QFormLayout* inputlhs = new QFormLayout();
	QVBoxLayout* input1 = new QVBoxLayout();
	QFormLayout* inputrhs = new QFormLayout();
	QVBoxLayout* input2 = new QVBoxLayout();
	user temp;
	vector<string> tempN = temp._name;
	string nameInput1 = " ";
	for (unsigned int i=0; i<tempN.size(); i++)
	{
		nameInput1 = nameInput1+" "+tempN[i];
	}
	nameInput->setPlaceholderText(QString::fromStdString(nameInput1));
	//dateinput->setPlaceholderText(Qstring::fromStdString(temp._date));	
	cellInput->setPlaceholderText(QString::fromStdString(temp._cell));	 
	cellInput2->setPlaceholderText(QString::fromStdString(temp._other));	
	email->setPlaceholderText(QString::fromStdString(temp._email));
	vector<string> tempA = temp._address;
	string addressInput1 = " ";
	for (unsigned int i=0; i<tempA.size(); i++)
	{
		addressInput1 = addressInput1+" "+tempA[i];
	}
	addressInput->setPlaceholderText(QString::fromStdString(addressInput1));
	referralInput->setPlaceholderText(QString::fromStdString(temp._Referral));
	brokerInput->setPlaceholderText(QString::fromStdString(temp._Broker));
	officeInput->setPlaceholderText(QString::fromStdString(temp._Office));
	ssnInput->setPlaceholderText(QString::fromStdString(temp._SSN));	
	income->setPlaceholderText(QString::fromStdString(temp._MonthlyIncome));	
	dob->setPlaceholderText(QString::fromStdString(temp._DOB));
	//ethnicity->setPalceholderText(QString::fromStdString(temp._Ethnicity));
	//gender->setPlaceholderText(QString::fromStdString(temp._Gender));
	occupation->setPlaceholderText(QString::fromStdString(temp._Occupation));

	


	title1Label = new QLabel("Customer Profile");
	labelLayout ->addWidget(title1Label);
	title2Label = new QLabel("Current Car Info(Use for trade-in)");
	labelLayout->addWidget(title2Label);
	overallLayout->addLayout(labelLayout);
	//inputlhs->addRow(tr("&Customer Profile"),title1Label);
	
	inputlhs->addRow(tr("&Name:"),nameInput);		
	inputlhs->addRow(tr("&Date:"),dateinput);	
	inputlhs->addRow(tr("&Cell #:"),cellInput);	
	inputlhs->addRow(tr("&other #:"),cellInput2);		
	inputlhs->addRow(tr("&Email:"),email);
	inputlhs->addRow(tr("&Address:"),addressInput);	
	inputlhs->addRow(tr("&Referral:"),referralInput);	
	inputlhs->addRow(tr("&Broker"),brokerInput);	
	inputlhs->addRow(tr("&Office"),officeInput);	
	inputlhs->addRow(tr("&SSN:"),ssnInput);	
	inputlhs->addRow(tr("&Monthly Income:"),income);
	inputlhs->addRow(tr("&DOB:"),dob);
	
	
	ethnicityLabel = new QLabel("Ethnicity:");
	inputlhs->addRow(ethnicity);
	

	gender = new QComboBox();
	genderLabel = new QLabel("Gender:");
	inputlhs->addRow(genderLabel);
	
	//Choose the way of listing
	gender->addItem("Male");
	gender->addItem("Female");
	inputlhs->addRow(gender);
	occupation = new QLineEdit();
	inputlhs->addRow(tr("&Occupation:"),occupation);
	input1->addLayout(inputlhs);
	inputLayout->addLayout(input1);

	

	inputrhs->addRow(tr("&Make:"),makeInput);
	
	inputrhs->addRow(tr("&Exterior Color:"),colorInput2);
	
	inputrhs->addRow(tr("&Interior Color:"),colorInput);
	
	inputrhs->addRow(tr("&Year:"),yearInput);
	
	inputrhs->addRow(tr("&M.R.S.P:"),mrsp);
	
	inputrhs->addRow(tr("&Current Value:"),valueInput);	
	
	inputrhs->addRow(tr("&Navigation:"),navigation);
	
	inputrhs->addRow(tr("&Rear Camera:"),RCamera);
	
	inputrhs->addRow(tr("&Additional Features:"),featureInput);
	input2->addLayout(inputrhs);
	inputLayout->addLayout(input2);
	//inputLayout->addLayout(inputlhs);
	/*inputLayout->addLayout(inputmhs);
	inputLayout->addLayout(inputrhs);*/
	overallLayout->addLayout(inputLayout);
	
	QPushButton* saveButton = new QPushButton("Save");
	connect(saveButton, SIGNAL(clicked()), this, SLOT(saveInput()));
	overallLayout->addWidget(saveButton);
	popWindow.setLayout(overallLayout);
	popWindow.exec();

	
	

	
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
	for (unsigned int i=0; i<userR.size(); i++)
	{
		std::string str1= userR[i].displayString();
		QString qstr1 = QString::fromStdString(str1);
		profileListWidget->addItem(qstr1);
	}
}

//save to file window
void MainWindow::exportPopup()
{

	QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "Home//","All files (*.*);;Text File(*.txt)");
	string name = fileName.toStdString();
	ofstream of(name.c_str());
	db.dump(of);
	of.close();

	/*save->setWindowTitle("Save to File");
	overallSLayout = new QVBoxLayout();
	saveLabel = new QLabel("Please input file name");
	overallSLayout->addWidget(saveLabel);
	
	okButton = new QPushButton("OK");
	connect(okButton, SIGNAL(clicked()), this, SLOT(ofile()));
	overallSLayout->addWidget(okButton);
	save->setLayout(overallSLayout);
	save->exec();*/
}

//function of ofile
void MainWindow::ofile()
{
	
	save->close();
}


void MainWindow::showPopup()
{

//TODO

//add call back date QCalendar
	QDialog popWindow;
	popWindow.setWindowTitle("Input Data");
	QVBoxLayout* overallLayout = new QVBoxLayout();
	QHBoxLayout* inputLayout = new QHBoxLayout();
	QHBoxLayout* labelLayout = new QHBoxLayout();
	QFormLayout* inputlhs = new QFormLayout();
	QVBoxLayout* input1 = new QVBoxLayout();
	QFormLayout* inputrhs = new QFormLayout();
	QVBoxLayout* input2 = new QVBoxLayout();


	title1Label = new QLabel("Customer Profile");
	labelLayout ->addWidget(title1Label);
	title2Label = new QLabel("Current Car Info(Use for trade-in)");
	labelLayout->addWidget(title2Label);
	overallLayout->addLayout(labelLayout);
	//inputlhs->addRow(tr("&Customer Profile"),title1Label);
	nameInput = new QLineEdit();
	inputlhs->addRow(tr("&Name:"),nameInput);	
	
	dateinput = new QLineEdit();
	inputlhs->addRow(tr("&Date:"),dateinput);
	cellInput = new QLineEdit();
	inputlhs->addRow(tr("&Cell #:"),cellInput);
	cellInput2 = new QLineEdit();
	inputlhs->addRow(tr("&other #:"),cellInput2);	
	email = new QLineEdit();
	addressInput = new QLineEdit();
	inputlhs->addRow(tr("&Email:"),email);
	inputlhs->addRow(tr("&Address:"),addressInput);
	referralInput = new QLineEdit();
	inputlhs->addRow(tr("&Referral:"),referralInput);
	brokerInput = new QLineEdit();
	inputlhs->addRow(tr("&Broker"),brokerInput);
	officeInput = new QLineEdit();
	inputlhs->addRow(tr("&Office"),officeInput);
	ssnInput = new QLineEdit();
	inputlhs->addRow(tr("&SSN:"),ssnInput);
	income = new QLineEdit();
	inputlhs->addRow(tr("&Monthly Income:"),income);
	dob = new QLineEdit();
	inputlhs->addRow(tr("&DOB:"),dob);
	
	ethnicity = new QComboBox();
	ethnicityLabel = new QLabel("Ethnicity:");
	inputlhs->addRow(ethnicityLabel);
	ethnicity->addItem("Asian");
	ethnicity->addItem("American Indian or Alaska Native");
	ethnicity->addItem("Black or African American");
	ethnicity->addItem("Native Hawaiian or Other Pacific Islander");
	ethnicity->addItem("White");
	inputlhs->addRow(ethnicity);
	

	gender = new QComboBox();
	genderLabel = new QLabel("Gender:");
	inputlhs->addRow(genderLabel);
	
	//Choose the way of listing
	gender->addItem("Male");
	gender->addItem("Female");
	inputlhs->addRow(gender);
	occupation = new QLineEdit();
	inputlhs->addRow(tr("&Occupation:"),occupation);
	input1->addLayout(inputlhs);
	inputLayout->addLayout(input1);

	

	makeInput = new QLineEdit();
	inputrhs->addRow(tr("&Make:"),makeInput);
	colorInput2 = new QLineEdit();
	inputrhs->addRow(tr("&Exterior Color:"),colorInput2);
	colorInput = new QLineEdit();
	inputrhs->addRow(tr("&Interior Color:"),colorInput);
	yearInput = new QLineEdit();
	inputrhs->addRow(tr("&Year:"),yearInput);
	mrsp = new QLineEdit();
	inputrhs->addRow(tr("&M.R.S.P:"),mrsp);
	valueInput = new QLineEdit();
	inputrhs->addRow(tr("&Current Value:"),valueInput);	
	navigation = new QLineEdit();
	inputrhs->addRow(tr("&Navigation:"),navigation);
	RCamera = new QLineEdit();
	inputrhs->addRow(tr("&Rear Camera:"),RCamera);
	featureInput = new QLineEdit();
	inputrhs->addRow(tr("&Additional Features:"),featureInput);
	input2->addLayout(inputrhs);
	inputLayout->addLayout(input2);
	//inputLayout->addLayout(inputlhs);
	/*inputLayout->addLayout(inputmhs);
	inputLayout->addLayout(inputrhs);*/
	overallLayout->addLayout(inputLayout);
	
	QPushButton* saveButton = new QPushButton("Save");
	connect(saveButton, SIGNAL(clicked()), this, SLOT(saveInput()));
	overallLayout->addWidget(saveButton);
	popWindow.setLayout(overallLayout);
	popWindow.exec();

}

void MainWindow::saveInput()
{
	string nameS = nameInput->text().toStdString();
	for(int i=0;i<(int)nameS.size();i++)
		if (nameS[i]==' ') nameS[i]='*';
	string dateS = dateinput->text().toStdString();
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
	ethnicity = new QComboBox();
	string ethnicityS;
	if (ethnicity->currentIndex() == 0)
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
	}
	string genderS;
	if (gender->currentIndex() == 0)
	{
		genderS = "Male";
	}
	else if (gender->currentIndex() == 1)
	{
		genderS = "Female";
	}

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
	user newUser(nameS,dateS,cellS,cell2S,addressInputS);
	newUser._email=emailS;
	newUser._Referral=referralS;
	newUser._Broker=brokerS;
	newUser._Office=officeS;
	newUser._SSN=ssnS;
	newUser._MonthlyIncome=incomeS;
	newUser._DOB=dobS;
	newUser._Ethnicity=ethnicityS;
	newUser._Gender=genderS;
	newUser._Occupation=occupationS;
	db.addUser(newUser);

}

