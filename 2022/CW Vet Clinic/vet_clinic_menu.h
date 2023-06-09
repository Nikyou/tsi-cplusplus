#include "vet_clinic.h"


void StringBounder(std::string& str, unsigned int i);

void Clear();

void AnyKeyReturn(int& outputsize);

time_t InputDate();

void FilesInitialise(std::vector<Species>& spec,
 std::string& specfile, std::vector<Characteristics>& charac,
 std::string& characfile, std::vector<Gender>& gen, std::string& genfile,
 std::vector<Animal>& animal, std::string& animalfile,
 std::vector<Owner>& owner, std::string& ownerfile,
 std::vector<Reason>& reason, std::string& reasonfile,
 std::vector<Appointment>& app, std::string& appfile);

std::string bool_to_string(const bool b);

void MenuDataSortingText(int& outputsize, const short int choice,
 const std::vector<unsigned short int> prio,
 const std::vector<std::string> sign);

void MenuDataSorting(int& outputsize, const short int oldchoice,
 std::vector<Animal>& animal, std::vector<Owner>& owner,
 std::vector<Appointment>& app, std::vector<unsigned short int> prio,
 std::vector<std::string> sign);

void MenuDataFiltersNextText(int& outputsize, const short int choice,
const unsigned short int selected);

void MenuDataFiltersNext(int& outputsize, const short int oldchoice,
 std::vector<Animal>& animal, std::vector<Owner>& owner,
 std::vector<Appointment>& app, std::vector<Species>& spec,
 std::vector<Characteristics>& charac, std::vector<Gender>& gen,
 std::vector<Reason>& reason, const unsigned short int object,
 const unsigned short int data, unsigned short int selected);

void MenuDataFiltersText(int& outputsize, const short int choice);

void MenuDataFilters(int& outputsize, const short int oldchoice,
 std::vector<Animal>& animal, std::vector<Owner>& owner,
 std::vector<Appointment>& app, std::vector<Species>& spec,
 std::vector<Characteristics>& charac, std::vector<Gender>& gen,
 std::vector<Reason>& reason);

void MenuDataSummaryNextText(int& outputsize, const short int choice,
 const unsigned short int selected);

void MenuDataSummaryNext(int& outputsize, const short int oldchoice,
 std::vector<Animal>& animal, std::vector<Owner>& owner,
 std::vector<Appointment>& app, std::vector<Species>& spec,
 std::vector<Characteristics>& charac, std::vector<Gender>& gen,
 std::vector<Reason>& reason, const unsigned short int object,
	const unsigned short int data, unsigned short int selected);

void MenuDataSummaryText(int& outputsize, const short int choice);

void MenuDataSummary(int& outputsize, const short int oldchoice,
 std::vector<Animal>& animal, std::vector<Owner>& owner,
 std::vector<Appointment>& app, std::vector<Species>& spec,
 std::vector<Characteristics>& charac, std::vector<Gender>& gen,
 std::vector<Reason>& reason);

void MenuDataShownText(int& outputsize, const short int choice,
 std::vector<bool>& ownershow, std::vector<bool>& animalshow,
 std::vector<bool>& appshow);

void MenuDataShown(int& outputsize, const short int oldchoice,
 std::vector<bool>& ownershow, std::vector<bool>& animalshow,
 std::vector<bool>& appshow);

void MenuShowObjectsAuxiliaryText(int& outputsize);

void MenuShowObjectsAuxiliary(int& outputsize, char& border,
 std::vector<Species>& spec, std::vector<Characteristics>& charac,
 std::vector<Gender>& gen, std::vector<Reason>& reason);

void MenuShowObjectsMainText(int& outputsize, short int& choice);

void MenuShowObjectsMain(int& outputsize, char& border, short int& oldchoice,
 std::vector<Animal>& origanimal, std::vector<Owner>& origowner,
 std::vector<Appointment>& origapp, std::vector<Species>& origspec,
 std::vector<Characteristics>& origchar, std::vector<Gender>& origgen,
 std::vector<Reason>& origreason);

void MenuShowObjectsText(int& outputsize);

void MenuShowObjects(int& outputsize, char& border,
 std::vector<Species>& origspec, std::vector<Characteristics>& origchar,
 std::vector<Gender>& origgen, std::vector<Animal>& origanimal,
 std::vector<Owner>& origowner, std::vector<Reason>& origreason,
 std::vector<Appointment>& origapp);

void MenuAddObjectsText(int& outputsize);

void MenuAddOwner(int& outputsize, char& border, std::vector<Owner>& owner,
 std::string& ownerfile, std::string& animalfile);

void MenuAddAnimal(int& outputsize, char& border, std::vector<Animal>& animal,
 std::string& animalfile, std::vector<Owner>& owner, std::string& ownerfile,
 std::vector<Species>& spec, std::vector<Characteristics>& charac,
 std::vector<Gender>& gen);

void MenuAddAppointment(int& outputsize, char& border,
 std::vector<Appointment>& app, std::string& appfile,
 std::vector<Reason>& reason);

void MenuAddSpecies(int& outputsize, std::vector<Species>& spec,
 std::string& specfile);

void MenuAddCharacteristics(int& outputsize,
 std::vector<Characteristics>& charac, std::string& characfile,
 std::vector<Species>& spec);

void MenuAddGender(int& outputsize, std::vector<Gender>& gen,
 std::string& genfile);

void MenuAddReason(int& outputsize, std::vector<Reason>& reason,
 std::string& reasonfile);

void MenuAddObjects(int& outputsize, char& border, std::vector<Animal>& animal,
 std::string& animalfile, std::vector<Owner>& owner, std::string& ownerfile,
 std::vector<Appointment>& app, std::string& appfile,
 std::vector<Species>& spec, std::string& specfile,
 std::vector<Characteristics>& charac, std::string& characfile,
 std::vector<Gender>& gen, std::string& genfile, std::vector<Reason>& reason,
 std::string& reasonfile);

void MenuRemoveObjectsNextText(int& outputsize, const short int choice);

void MenuRemoveObjectsNext(int& outputsize, char& border,
 const short int oldchoice, std::vector<Animal>& animal,
 std::string& animalfile, std::vector<Owner>& owner, std::string& ownerfile,
 std::vector<Appointment>& app, std::string& appfile,
 std::vector<Species>& spec, std::string& specfile,
 std::vector<Characteristics>& charac, std::string& characfile,
 std::vector<Gender>& gen, std::string& genfile, std::vector<Reason>& reason,
 std::string& reasonfile);

void MenuRemoveObjectsText(int& outputsize);

void MenuRemoveObjects(int& outputsize, char& border,
 std::vector<Animal>& animal, std::string& animalfile,
 std::vector<Owner>& owner, std::string& ownerfile,
 std::vector<Appointment>& app, std::string& appfile,
 std::vector<Species>& spec, std::string& specfile,
 std::vector<Characteristics>& charac, std::string& characfile,
 std::vector<Gender>& gen, std::string& genfile, std::vector<Reason>& reason,
 std::string& reasonfile);

void MenuEditOwner(int& outputsize, const int b, const int i,
 std::vector<Owner>& owner, std::string& ownerfile,
 std::vector<Animal>& animal, std::string& animalfile,
 std::vector<Appointment>& app, std::string& appfile);

void MenuEditAnimal(int& outputsize, const int b, const int i,
 std::vector<Owner>& owner, std::string& ownerfile,
 std::vector<Animal>& animal, std::string& animalfile,
 std::vector<Appointment>& app, std::string& appfile,
 std::vector<Species>& spec, std::vector<Characteristics>& charac,
 std::vector<Gender>& gen);

void MenuEditAppointment(int& outputsize, const int b,
 std::vector<Appointment>& app, std::string& appfile,
 std::vector<Reason>& reason);

void MenuEditCharacteristics(int& outputsize, const int b,
 std::vector<Characteristics>& charac, std::string& characfile,
 std::vector<Species>& spec, std::vector<Animal>& animal,
 std::string& animalfile);

void MenuEditObjectsNextText(int& outputsize, const short int choice);

void MenuEditObjectsNext(int& outputsize, const short int oldchoice,
 std::vector<Animal>& animal, std::string& animalfile,
 std::vector<Owner>& owner, std::string& ownerfile,
 std::vector<Appointment>& app, std::string& appfile,
 std::vector<Species>& spec, std::string& specfile,
 std::vector<Characteristics>& charac, std::string& characfile,
 std::vector<Gender>& gen, std::string& genfile, std::vector<Reason>& reason,
 std::string& reasonfile);

void MenuEditObjectsText(int& outputsize);

void MenuEditObjects(int& outputsize, std::vector<Animal>& animal,
 std::string& animalfile, std::vector<Owner>& owner, std::string& ownerfile,
 std::vector<Appointment>& app, std::string& appfile,
 std::vector<Species>& spec, std::string& specfile,
 std::vector<Characteristics>& charac, std::string& characfile,
 std::vector<Gender>& gen, std::string& genfile, std::vector<Reason>& reason,
 std::string& reasonfile);

void MenuText(int& outputsize);

void Menu(int& outputsize, char& border, std::string& specfile,
 std::string& characfile, std::string& genfile, std::string& animalfile,
 std::string& ownerfile, std::string& reasonfile, std::string& appfile);