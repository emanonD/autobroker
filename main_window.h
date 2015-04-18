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
//#include "dbase/msort.h"
#include "dbase/dbase.h"
#include "dbase/user.h"
#include "dbase/car.h"
#include "dbase/callHistory.h"
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
	void setToDate();
	void choice();
	void selectFile();
	void viewPopup();
	void saveInput();
	void editUser();
	void changeSave();
	void callHistory();
	void viewSpecific();
	void detailsPopup();
	void cancelCHPopup();
	void cancelPopup();
	void uploadP();
	void uploadF();
	void addCallPopup();
	void seeDetails(int index);
	void saveDPopup();
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
	QHBoxLayout* overallLayout;
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
	QRadioButton* searchFile; 
	QRadioButton* inputFile; 
	QRadioButton* exportFile; 
	QRadioButton* viewPlan;
	QPushButton* ok1Button; 
	QPushButton* callButton;
	QPushButton* inputData;
	QLineEdit* email;
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
	QLineEdit* valueInput;
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
	void showPopup();
	void exportPopup();
	void searchPopup();
	void ofile();
	void sortN(vector<user> r);
	void sortD(vector<user> r);
	void saveSuccess();
	void planPopup();
	void changeSuccess();
	void successmsg();

};