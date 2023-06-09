#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <limits>


struct Species {  //auxiliary
    char species[60];
};

struct Characteristics {  //auxiliary
    char breed[60];
    Species species;
};

struct Gender {  //auxiliary
    char gender[60];
};

struct Animal {  //main
    unsigned int animal_id;
    char name[60];
    Characteristics characteristics;
    Gender gender;
    unsigned short int age;
    float weight;
    unsigned int owner_id;
};

struct Owner {  //main
    unsigned int owner_id;
    char full_name[80];
    unsigned short int number_of_animals;
};

struct Reason {  //auxiliary
    char reason[80];
};

struct Appointment { //main
    unsigned int appointment_id;
    unsigned int owner_id;
    unsigned int animal_id;
    time_t date;
    Reason reason;
    char commentary[160];
};

std::string Removespaces(std::string str);


void Outputconverter(std::vector<char>& strv, int outputsize,
 unsigned int n = 1, bool formating = false, char border = '#',
 bool endc = false);

void Outputconverter(std::string& str, int outputsize, unsigned int n = 1,
 bool formating = false, char border = '#', bool endc = false); 


bool CompareReasonasc(Reason& r1, Reason& r2);

void SaveReason(std::vector<Reason>& reason, std::string& file);

void ReadReason(std::vector<Reason>& reason, std::string& file);

std::string StrTabOutputReason(Reason& reason, unsigned int& i,
int& outputsize, char& border);

std::string StrHeaderReason(int& outputsize, char& border);

void TableOutputReason(std::vector<Reason>& reason, int& outputsize,
 char border = '#');


bool CompareGenderasc(Gender& g1, Gender& g2);

void SaveGender(std::vector<Gender>& gender, std::string& file);

void ReadGender(std::vector<Gender>& gender, std::string& file);

std::string StrTabOutputGender(Gender& gender, unsigned int& i,
 int& outputsize, char& border);

std::string StrHeaderGender(int& outputsize, char& border);

void TableOutputGender(std::vector<Gender>& gender, int& outputsize,
 char border = '#');


bool CompareSpeciesasc(Species& s1, Species& s2);

void SaveSpecies(std::vector<Species>& species, std::string& file);

void ReadSpecies(std::vector<Species>& species, std::string& file);

std::string StrTabOutputSpecies(Species& species, unsigned int& i,
 int& outputsize, char& border);

std::string StrHeaderSpecies(int& outputsize, char& border);

void TableOutputSpecies(std::vector<Species>& species, int& outputsize,
 char border = '#');


bool CompareCharacteristicsbyspecasc(Characteristics& c1,
 Characteristics& c2);

bool CompareCharacteristicsbybreedasc(Characteristics& c1,
 Characteristics& c2);

void SaveCharacteristics(std::vector<Characteristics>& characteristics,
 std::string& file);

void ReadCharacteristics(std::vector<Characteristics>& characteristics,
 std::string& file);

std::string StrTabOutputCharacteristics(Characteristics& characteristics,
 unsigned int& i, int& outputsize, char& border);

std::string StrHeaderCharacteristics(int& outputsize, char& border);

void TableOutputCharacteristics(std::vector<Characteristics>& characteristics,
 int& outputsize, char border = '#');


void SaveAnimal(std::vector<Animal>& animal, std::string& file);

void ReadAnimal(std::vector<Animal>& animal, std::string& file);

void DeleteDataAnimal(std::vector<Animal>& animal, unsigned int id,
 std::string file, unsigned short int i = 1);

bool CompareAnimalbyidasc(Animal& a1, Animal& a2);

bool CompareAnimalbyiddec(Animal& a1, Animal& a2);

bool CompareAnimalbynameasc(Animal& a1, Animal& a2);

bool CompareAnimalbynamedec(Animal& a1, Animal& a2);

bool CompareAnimalbyspeciesasc(Animal& a1, Animal& a2);

bool CompareAnimalbyspeciesdec(Animal& a1, Animal& a2);

bool CompareAnimalbybreedasc(Animal& a1, Animal& a2);

bool CompareAnimalbybreeddec(Animal& a1, Animal& a2);

bool CompareAnimalbygenderasc(Animal& a1, Animal& a2);

bool CompareAnimalbygenderdec(Animal& a1, Animal& a2);

bool CompareAnimalbyageasc(Animal& a1, Animal& a2);

bool CompareAnimalbyagedec(Animal& a1, Animal& a2);

bool CompareAnimalbyweightasc(Animal& a1, Animal& a2);

bool CompareAnimalbyweightdec(Animal& a1, Animal& a2);

bool CompareAnimalbyoidasc(Animal& a1, Animal& a2);

bool CompareAnimalbyoiddec(Animal& a1, Animal& a2);

void SortAnimal(std::vector<Animal>& result,
 std::vector<unsigned short int>& prio, std::vector<std::string>& sign);

std::vector<Animal> FilterAnimal(std::vector<Animal> result,
 std::vector<std::string>& sign, unsigned int& animal_id, std::string& species,
 std::string& breed, std::string& gender, unsigned int& age,
 float& weight, unsigned int& owner_id);

unsigned int SummaryAnimal(std::vector <Animal> result,
 std::vector<std::string>& sign, std::string& species, std::string& breed,
 std::string& gender, unsigned int& age, float& weight);

std::string StrTabOutputAnimal(Animal& animal, unsigned int& i,
 int& outputsize, char& border, std::vector<bool>& show);

std::string StrHeaderAnimal(int& outputsize, char& border,
 std::vector<bool>& show);

void TableOutputAnimal(std::vector<Animal>& animal, int& outputsize,
 char& border, std::vector<bool>& show);


void SaveOwner(std::vector<Owner>& owner, std::string& file);

void ReadOwner(std::vector<Owner>& owner, std::string& file);

void DeleteDataOwner(std::vector<Owner>& owner,
 std::vector<Appointment>& appointment, std::vector<Animal>& animal,
 unsigned int id, std::string ofile, std::string apfile, std::string afile,
 unsigned short int i = 1);

void UpdateNoAOwner(std::string& fileowner, std::string& fileanimal);

bool CompareOwnerbyidasc(Owner& o1, Owner& o2);

bool CompareOwnerbyiddec(Owner& o1, Owner& o2);

bool CompareOwnerbynameasc(Owner& o1, Owner& o2);

bool CompareOwnerbynamedec(Owner& o1, Owner& o2);

bool CompareOwnerbynoaasc(Owner& o1, Owner& o2);

bool CompareOwnerbynoadec(Owner& o1, Owner& o2);

void SortOwner(std::vector<Owner>& result,
 std::vector<unsigned short int>& prio, std::vector<std::string>& sign);

std::vector<Owner> FilterOwner(std::vector<Owner> result,
 std::vector<std::string>& sign, unsigned int& owner_id,
 unsigned int& noa);

unsigned int SummaryOwner(std::vector<Owner> result, unsigned int& noa,
 std::string& noasign);

std::string StrTabOutputOwner(Owner& owner, unsigned int& i, int& outputsize,
 char& border, std::vector<bool>& show);

std::string StrHeaderOwner(int& outputsize, char& border,
 std::vector<bool>& show);

void TableOutputOwner(std::vector<Owner>& owner, int& outputsize, char& border,
 std::vector<bool>& show);


void SaveAppointment(std::vector<Appointment>& appointment,
 std::string& file);

void ReadAppointment(std::vector<Appointment>& appointment,
 std::string& file);

void DeleteDataAppointment(std::vector<Appointment>& appointment,
 unsigned int id, std::string file, unsigned short int i = 1);

bool CompareAppointmentbyidasc(Appointment& ap1, Appointment& ap2);

bool CompareAppointmentbyiddec(Appointment& ap1, Appointment& ap2);

bool CompareAppointmentbyoidasc(Appointment& ap1, Appointment& ap2);

bool CompareAppointmentbyoiddec(Appointment& ap1, Appointment& ap2);

bool CompareAppointmentbyaidasc(Appointment& ap1, Appointment& ap2);

bool CompareAppointmentbyaiddec(Appointment& ap1, Appointment& ap2);

bool CompareAppointmentbydateasc(Appointment& ap1, Appointment& ap2);

bool CompareAppointmentbydatedec(Appointment& ap1, Appointment& ap2);

bool CompareAppointmentbyreasonasc(Appointment& ap1, Appointment& ap2);

bool CompareAppointmentbyreasondec(Appointment& ap1, Appointment& ap2);

void SortAppointment(std::vector<Appointment>& result,
 std::vector<unsigned short int>& prio, std::vector<std::string>& sign);

std::vector<Appointment> FilterAppointment(std::vector<Appointment> result,
 std::vector<std::string>& sign, unsigned int& appointment_id,
 unsigned int& owner_id, unsigned int& animal_id, time_t& date,
 std::string& reason);

unsigned int SummaryAppointment(std::vector<Appointment> result,
 std::vector<std::string>& sign, unsigned int& owner_id,
 unsigned int& animal_id, time_t& date, std::string& reason);

std::string StrTabOutputAppointment(Appointment& appointment, unsigned int& i,
 int& outputsize, char& border, std::vector<bool>& show);

std::string StrHeaderAppointment(int& outputsize, char& border,
 std::vector<bool>& show);

void TableOutputAppointment(std::vector<Appointment>& appointment,
 int& outputsize, char& border, std::vector<bool>& show);