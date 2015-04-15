#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QFileDialog>
#include <QScrollArea>
#include <QPushButton>
#include <QRadioButton>
#include <QMessageBox>
#include <QListWidget>
#include <QDialog>
#include <QFormLayout>
#include <QGroupBox>
#include <string>
#include <vector>
#include <fstream>
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
	
	void choice();
	void selectFile();
	void viewPopup();
	void saveInput();
	void editUser();
	
private:
	//dbase db();
	vector<user> userR;
	QHBoxLayout* overallLayout;
	QVBoxLayout* lhsLayout;
	QVBoxLayout* buttonLayout;
	
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
	QLabel* genderLabel;
QLineEdit* income;
QLineEdit* dateinput;
QLineEdit* cellInput2;
QLineEdit* occupation;
	QDialog* save;
	QVBoxLayout* overallSLayout; 
	QLabel* saveLabel;	
	QLineEdit* saveEdit;
	QPushButton* okButton;

	QLineEdit* colorInput2;
	QLineEdit* yearInput;
	QLineEdit* mrsp;
	QLineEdit* navigation;
	QLineEdit* RCamera;
	//void viewPopup();
	void showPopup();
	void exportPopup();
	void searchPopup();
	void ofile();
};