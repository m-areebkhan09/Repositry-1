#include <iostream>
#include <vector>
using namespace std;

/*
This is 19-July-2024
*/

// 1) Function To Admit Patients (Name, Age, Gender, Medical Condition):

int RANDOM_ID = 701400;

void Admit_Patient(vector<long> &ID, vector<string> &name, vector<int> &age, vector<string> &gender, vector<string> &medical_condition)
{
  ID.push_back(RANDOM_ID);
  RANDOM_ID = RANDOM_ID + 1;

  string Patient_name;
  cout << "Enter Patient Name(Without Spaces In UPPER CASE):";
  cin >> Patient_name;
  name.push_back(Patient_name);

  int Patient_Age;
  cout << "Enter Patient Age:";
  cin >> Patient_Age;
  age.push_back(Patient_Age);

  string Patient_Geneder;
  cout << "Enter Patient Gender(Without Spaces In UPPER CASE):";
  cin >> Patient_Geneder;
  gender.push_back(Patient_Geneder);

  string Patient_Medical_Condition;
  cout << "Enter Patient Medical Condition(Without Spaces In UPPER CASE):";
  cin >> Patient_Medical_Condition;
  medical_condition.push_back(Patient_Medical_Condition);
}

// 2) Function To Display List of Patients:

void Patients_List(vector<long> ID, vector<string> name, vector<int> age, vector<string> gender, vector<string> medical_condition)
{
  for (int i = 0; i < name.size(); i++)
  {
    cout << "Patient ID: " << ID[i] << endl;
    cout << "Patient Name: " << name[i] << endl;
    cout << "Patient Age: " << age[i] << endl;
    cout << "Patient Gender: " << gender[i] << endl;
    cout << "Patient Medical Condition: " << medical_condition[i] << endl;
    cout << endl;
  }
}

// 3)Function To Search Patient By Their ID:

void Search_Patient_by_ID(vector<long> ID, vector<string> name, vector<int> age, vector<string> gender, vector<string> medical_condition)
{

  int Key;
  cout << "Enter patient ID: ";
  cin >> Key;

  int index = -1;

  for (int i = 0; i < ID.size(); i++)
  {
    if (ID[i] == Key)
    {
      index = i;
    }
  }

  if (index != -1)
  {

    cout << "Patient ID: " << ID[index] << endl;
    cout << "Patient Name: " << name[index] << endl;
    cout << "Patient Age: " << age[index] << endl;
    cout << "Patient Gender: " << gender[index] << endl;
    cout << "Patient Medical Condition: " << medical_condition[index] << endl;
    cout << endl;
  }
  else
    cout << "Patient Not Found." << endl;
}

// 4)Function List of Patients With Same Disease:

void Patients_Same_Disease(vector<long> ID, vector<string> name, vector<int> age, vector<string> gender, vector<string> medical_condition)
{

  string disease;
  cout << "Enter Patient Medical Condition(Without Spaces In UPPER CASE):";
  cin >> disease;

  vector<int> targets;

  for (int i = 0; i < medical_condition.size(); i++)
  {
    if (disease == medical_condition[i])
    {
      targets.push_back(i);
    }
  }

  if (targets.size() != 0)
  {

    for (int i = 0; i < targets.size(); i++)
    {
      cout << "Patient ID: " << ID[targets[i]] << endl;
      cout << "Patient Name: " << name[targets[i]] << endl;
      cout << "Patient Age: " << age[targets[i]] << endl;
      cout << "Patient Gender: " << gender[targets[i]] << endl;
      cout << "Patient Medical Condition: " << medical_condition[targets[i]] << endl;
      cout << endl;
    }
  }
  else
    cout << "No Such Patients Found In The System";
}

// 5)Function to discharge patients:

void discharge_patient(vector<long> &ID, vector<string> &name, vector<int> &age, vector<string> &gender, vector<string> &medical_condition)
{
  long target;
  cout << "Enter patient ID to who you want to discharge: ";
  cin >> target;

  int target_index = -1;

  for (int i = 0; i < ID.size(); i++)
  {
    if (ID[i] == target)
    {
      target_index = i;
    }
  }

  if (target_index != -1)
  {
    ID.erase(ID.begin() + target_index);
    name.erase(name.begin() + target_index);
    age.erase(age.begin() + target_index);
    gender.erase(gender.begin() + target_index);
    medical_condition.erase(medical_condition.begin() + target_index);
    cout << target << " Has Been Discharged!" << endl;
  }
  else
    cout << "No Such Patient Found In The System!" << endl;
}

// 6)Function Display list of Doctors:

void Doctors_List(string DOC_NAME[], string DOC_AVAIL[], string DOC_SPECIAL[])
{

  for (int i = 0; i < 5; i++)
  {
    cout << "Doctor Name: " << DOC_NAME[i] << endl;
    cout << "Doctor Specialization : " << DOC_SPECIAL[i] << endl;
    cout << "Doctor Availability: " << DOC_AVAIL[i] << endl;
    cout << endl;
  }
}

int main()
{

  cout << "Welcome AAA Hospital" << endl;

  // Patients Details:
  vector<long> Patient_ID;
  vector<string> Patient_NAME;
  vector<int> Patient_AGE;
  vector<string> Patient_GENDER;
  vector<string> Patient_Medical_CONDITION;

  // Doctors Details:
  string Doctors_Name[5] = {"Dr Abdullah Kaleem", "Dr Muhammad Ammar Qaisar", "Dr Areeb Khan", "Dr Muhammad Almas Manzoor", "Dr Muhammad Moin Juddu"};
  string Doctors_Availability[5] = {"Monday to Friday \n 8:00 to 14:00", "Only Monday \n 10:00 to 10:15", "24/7", "Saturday & Sunday \n 8:00 to 17:00", "ON HOLIDAYS"};
  string Doctors_Specialization[5] = {"Surgeon", "Oncologist", "General Physician", "Endocrinologist", "Optometrist"};

  int choice;

  cout << "Press 1: To Add Patients" << endl;
  cout << "Press 2: To Display List of Patients" << endl;
  cout << "Press 3: To Search Patients by Patient ID" << endl;
  cout << "Press 4: To Display List of Patients With Same Disease" << endl;
  cout << "Press 5: To Discharge patient" << endl;
  cout << "Press 6: To Display Doctors List" << endl;
  cout << "Press 0: To Exit." << endl;

  cin >> choice;

  while (choice != 0)
  {

    if (choice == 1)
    {
      Admit_Patient(Patient_ID, Patient_NAME, Patient_AGE, Patient_GENDER, Patient_Medical_CONDITION);
    }
    else if (choice == 2)
    {
      Patients_List(Patient_ID, Patient_NAME, Patient_AGE, Patient_GENDER, Patient_Medical_CONDITION);
    }
    else if (choice == 3)
    {
      Search_Patient_by_ID(Patient_ID, Patient_NAME, Patient_AGE, Patient_GENDER, Patient_Medical_CONDITION);
    }
    else if (choice == 4)
    {
      Patients_Same_Disease(Patient_ID, Patient_NAME, Patient_AGE, Patient_GENDER, Patient_Medical_CONDITION);
    }
    else if (choice == 5)
    {
      discharge_patient(Patient_ID, Patient_NAME, Patient_AGE, Patient_GENDER, Patient_Medical_CONDITION);
    }
    else if (choice == 6)
    {
      Doctors_List(Doctors_Name,Doctors_Availability,Doctors_Specialization);
    }
    else if (choice == 0)
    {
      break;
    }
    else
    {
      cout << "Invalid Choice.";
      break;
    }

    cout << "Press 1: To Add Patients" << endl;
    cout << "Press 2: To Display List of Patients" << endl;
    cout << "Press 3: To Search Patients by Patient ID" << endl;
    cout << "Press 4: To Display List of Patients With Same Disease" << endl;
    cout << "Press 5: To Discharge patient" << endl;
    cout << "Press 6: To Display Doctors List" << endl;
    cout << "Press 0: To Exit." << endl;

    cin >> choice;
  }

  cout << "Thank You For Chosing Our Serivce! " << endl
       << endl;
  cout << "Programmed By: " << endl;
  cout << "Muhammad Ammar Qaisar" << endl;
  cout << "Abdullah Kaleem" << endl;
  cout << "Muhammad Areeb Khan " << endl;

  return 0;
}
