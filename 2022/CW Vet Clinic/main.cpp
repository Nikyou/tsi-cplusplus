#include "vet_clinic_menu.h"

int OutputSize = 80; //constant for output size;
char Border = '#';
std::string SpeciesFile = "species.dat";
std::string CharacteristicsFile = "characteristics.dat";
std::string GenderFile = "gender.dat";
std::string AnimalFile = "animal.dat";
std::string OwnerFile = "owner.dat";
std::string ReasonFile = "reason.dat";
std::string AppointmentFile = "appointment.dat";

int main() {
   Menu(OutputSize, Border, SpeciesFile, CharacteristicsFile, GenderFile,
    AnimalFile, OwnerFile, ReasonFile, AppointmentFile);
    return 0;
}