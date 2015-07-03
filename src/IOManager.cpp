#include "IOManager.h"

IOManager::IOManager() {

}

IOManager::~IOManager() {

}

int IOManager::generateNewGun()
{
    IOManager io;

    srand(time(NULL));

    int GunID = RandomGen::RandomNumber(1000, 1);

    int damage = RandomGen::RandomNumber(100, 1);

    int fireRate = RandomGen::RandomNumber(100, 10);

    int gunnum = RandomGen::RandomNumber(io.gunTypes.size(), 0);

    std::string gunType = io.gunTypes[gunnum];

    std::string ammo = io.ammoTypes[gunnum];

    std::string gunName = gunType;

    boost::property_tree::ptree pt;
    boost::property_tree::ptree children;
    boost::property_tree::ptree child1, child2;

    child1.put("GunID", GunID);
    child1.put("Name", gunName);
    child1.put("Class", gunType);
    child1.put("ClassID", gunnum);

    child2.put("Damage", damage);
    child2.put("Fire Rate", fireRate);
    child2.put("Requires", ammo);

    children.push_back(std::make_pair("Description", child1));
    children.push_back(std::make_pair("Stats", child2));

    pt.add_child("Gun", children);

    gunName = "Output/Guns/" + gunName + ".json";

    write_json(gunName, pt);

    std::cout << "Generated " << gunName << std::endl;

    return 0;
}

int IOManager::ActorJSONParser(std::string filePath)
{
    printf("Reading and Parsing Actor Json.\n");

    try
    {
        std::string ss = filePath;
        // send your JSON above to the parser below, but populate ss first

        boost::property_tree::ptree pt;
        boost::property_tree::read_json(ss, pt);

        boost::optional<int> ActorID = pt.get_optional<int>("Actor.Description.ActorID");
        boost::optional<std::string> ActorName = pt.get_optional<std::string>("Actor.Description.Name");
        boost::optional<std::string> ActorClass = pt.get_optional<std::string>("Actor.Description.Class");
        boost::optional<int> ActorClassID = pt.get_optional<int>("Actor.Description.ClassID");
        boost::optional<std::string> ActorRace = pt.get_optional<std::string>("Actor.Description.Race");
        boost::optional<int> ActorRaceID = pt.get_optional<int>("Actor.Description.RaceID");
        boost::optional<int> ActorHP = pt.get_optional<int>("Actor.Description.HP");

        std::cout << "Extracted ActorID: " << ActorID << std::endl;
        std::cout << "Extracted Actor Name: " << ActorName << std::endl;
        std::cout << "Extracted Actor Class: " << ActorClass << std::endl;
        std::cout << "Extracted Actor Class ID: " << ActorClassID << std::endl;
        std::cout << "Extracted Actor Race: " << ActorRace << std::endl;
        std::cout << "Extracted Actor Race ID: " << ActorRaceID << std::endl;
        std::cout << "Extracted Actor HP: " << ActorHP << std::endl;

        boost::optional<int> ActorStrength = pt.get_optional<int>("Actor.Stats.Strength");
        boost::optional<int> ActorAgility = pt.get_optional<int>("Actor.Stats.Agility");
        boost::optional<int> ActorConstitution = pt.get_optional<int>("Actor.Stats.Constitution");
        boost::optional<int> ActorIntelligence = pt.get_optional<int>("Actor.Stats.Intelligence");
        boost::optional<int> ActorWisdom = pt.get_optional<int>("Actor.Stats.Wisdom");
        boost::optional<int> ActorCharisma = pt.get_optional<int>("Actor.Stats.Charisma");
        boost::optional<int> ActorAC = pt.get_optional<int>("Actor.Stats.AC");
        boost::optional<int> ActorInitiative = pt.get_optional<int>("Actor.Stats.Initiative");
        boost::optional<int> ActorCMB = pt.get_optional<int>("Actor.Stats.CMB");
        boost::optional<int> ActorCMD = pt.get_optional<int>("Actor.Stats.CMD");

        std::cout << "Extracted Actor Strength: " << ActorStrength << std::endl;
        std::cout << "Extracted Actor Agility: " << ActorAgility << std::endl;
        std::cout << "Extracted Actor Constitution: " << ActorConstitution << std::endl;
        std::cout << "Extracted Actor Intelligence: " << ActorIntelligence << std::endl;
        std::cout << "Extracted Actor Wisdom: " << ActorWisdom << std::endl;
        std::cout << "Extracted Actor Charisma: " << ActorCharisma << std::endl;
        std::cout << "Extracted Actor AC: " << ActorAC << std::endl;
        std::cout << "Extracted Actor Initiative: " << ActorInitiative << std::endl;
        std::cout << "Extracted Actor CMB: " << ActorCMB << std::endl;
        std::cout << "Extracted Actor CMD: " << ActorCMD << std::endl;

        boost::optional<int> ActorFortitude = pt.get_optional<int>("Actor.Saves.Fortitude Save");
        boost::optional<int> ActorReflex = pt.get_optional<int>("Actor.Saves.Reflex Save");
        boost::optional<int> ActorWill = pt.get_optional<int>("Actor.Saves.Will Save");

        std::cout << "Extracted Actor Fortitude Save: " << ActorFortitude << std::endl;
        std::cout << "Extracted Actor Reflex Save: " << ActorReflex << std::endl;
        std::cout << "Extracted Actor Will Save: " << ActorWill << std::endl;

        boost::optional<int> ActorStrMod = pt.get_optional<int>("Actor.Stat Modifiers.Strength");
        boost::optional<int> ActorAgiMod = pt.get_optional<int>("Actor.Stat Modifiers.Agility");
        boost::optional<int> ActorConMod = pt.get_optional<int>("Actor.Stat Modifiers.Constitution");
        boost::optional<int> ActorIntMod = pt.get_optional<int>("Actor.Stat Modifiers.Intelligence");
        boost::optional<int> ActorWisMod = pt.get_optional<int>("Actor.Stat Modifiers.Wisdom");
        boost::optional<int> ActorChaMod = pt.get_optional<int>("Actor.Stat Modifiers.Charisma");

        std::cout << "Extracted Actor Strength Mod: " << ActorStrMod << std::endl;
        std::cout << "Extracted Actor Agility Mod: " << ActorAgiMod << std::endl;
        std::cout << "Extracted Actor Constitution Mod: " << ActorConMod << std::endl;
        std::cout << "Extracted Actor Intelligence Mod: " << ActorIntMod << std::endl;
        std::cout << "Extracted Actor Wisdom Mod: " << ActorWisMod << std::endl;
        std::cout << "Extracted Actor Charisma Mod: " << ActorChaMod << std::endl;

        return EXIT_SUCCESS;
    }
    catch (std::exception const& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
