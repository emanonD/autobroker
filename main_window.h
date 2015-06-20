#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QFileDialog>
#include <QScrollArea>
#include <QCalendarWidget>
#include <QPushButton>
#include <QRadioButton>
#include <QMessageBox>
#include <QDate>
#include <QListWidget>
#include <QDialog>
#include <QFormLayout>
#include <QGroupBox>
#include <QPicture>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <QTableWidget>
//#include "dbase/msort.h"
#include "dbase/dbase.h"
#include "dbase/user.h"
#include "dbase/car.h"
#include "dbase/callHistory.h"
#include <stdio.h>
#include <stdlib.h>
//#include "dbase/callHistory.h"
//dbase db();

// The overall window
class MainWindow: public QWidget
{
	Q_OBJECT
public:
	MainWindow();
	~MainWindow();

private slots:
//void viewMonth();
	//void setToDate();
	//void choice();
	void selectFile();
	void viewPopup();
	void saveInput();
	void saveInput2();
	void excelPopup();
	void deleteLead();
	void deleteCustomer();
	//void editUser();
	//void changeSave();
	//void callHistory();
	//void viewSpecific();
	//void detailsPopup();
	//void cancelCHPopup();
	//void cancelPopup();
	//void addCallPopup();
	//void seeDetails(int index);
	//void saveDPopup();
	void reminder();
	void showPopup();
	void newUserPopup();
	void popUpModifier(int index);
private:
	//dbase db();
	vector<user> userR;
	vector<QString> _keepImages;
	vector<QString> _keepFiles;
	vector<QImage*> addressKeep;
	QDate selectedDate;
	QCalendarWidget* planC;
	QString selectedDateQS;
	QLabel* fileContainer;
	//QHBoxLayout* overallLayout;
	QTableWidget* leadsWidget;
	QTableWidget* customersWidget;
	QDialog* excelWindow;
	QVBoxLayout* lhsLayout;
	QVBoxLayout* buttonLayout;
	QDialog* historyWindow;
	QGridLayout* listLayout;
	QPushButton* ok1;
	QComboBox* list;
	QLabel* listLabel;
	QLineEdit* brokerInput;
	QLineEdit* officeInput;
	QGridLayout* searchButtons;
	QPushButton* editButton;
	QLabel* search;
	QLineEdit* searchInput;
	QPushButton* viewFile;
	QListWidget* profileListWidget;
	QLabel* select; 
	QPushButton* searchFile; 
	QPushButton* inputFile; 
	QPushButton* viewPlan;
	QPushButton* ok1Button; 
	QPushButton* callButton;
	QPushButton* inputData;
	QHBoxLayout* cellLayout;
	QVBoxLayout* overallLayout;
	QLineEdit* email;
	QLineEdit* cell1;
	QLineEdit* cell2;
	QLineEdit* cell3;
	QLineEdit* modelInput;
	QLineEdit* msrpInput;
	QLineEdit* optionsInput;
	QLineEdit* dotdInput;
	QLineEdit* downInput;
	QLineEdit* termInput;
	QLineEdit* milesInput;
	QFormLayout* inputlhs;
	QLineEdit* dob;
	QLabel* welcome;
	QLabel* title1Label;
	QLineEdit* nameInput;
	QLineEdit* cellInput;
	QLineEdit* addressInput;
	QLineEdit* referralInput;
	QLineEdit* ssnInput;
	QComboBox* ethnicity;
	QLabel* ethnicityLabel;
	QLabel* title2Label;
	QLineEdit* makeInput;
	QLineEdit* colorInput;
	QLineEdit* priceInput;
	QLineEdit* featureInput;
	QComboBox* gender;
	QDialog* popWindow;
	QLabel* genderLabel;
	QLineEdit* income;
	QLineEdit* dateinput;
	QLineEdit* cellInput2;
	QLineEdit* occupation;
	QDialog* save;
	QTextEdit* commentInput;
	QVBoxLayout* overallSLayout; 
	QLabel* saveLabel;	
	QLineEdit* saveEdit;
	QPushButton* okButton;
	QCalendarWidget* editC;
	QLineEdit* colorInput2;
	QLineEdit* yearInput;
	QLineEdit* mrsp;
	QLineEdit* navigation;
	QLineEdit* RCamera;
	QComboBox* purpose;
	QDialog* popWindows;
	QListWidget* listHistory;
	QDialog* window;
	string saveKey;
	QListWidget* showAddressF;
	QDialog* addCallWindow;


	QLineEdit* makeInputC;
	QLineEdit* colorInput2C;
	QComboBox* purposeC;
	QCalendarWidget* editCC;
	QLineEdit* colorInputC;
	QLineEdit* yearInputC;
	
	QLineEdit* mrspC;
	
	QLineEdit* valueInputC;
	
	QLineEdit* navigationC;
	QLineEdit* RCameraC;
	QLineEdit* featureInputC;
	
	//void viewPopup();
	vector<QImage*> Images;
	QLabel* ImageContainer;
	QListWidget* showAddress;
	
	void exportPopup();
	void searchPopup();
	void ofile();
	void sortN(vector<user> r);
	void sortD(vector<user> r);
	void saveSuccess();
	void planPopup();
	void changeSuccess();
	void successmsg();
	void saveToBackup();

};