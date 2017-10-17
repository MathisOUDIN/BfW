#include "state.hpp"

namespace state {
    
    bool unitTest_shouldCreatState() {
        State* state = new State();
        return (state != NULL);
    }

    bool unitTest_shouldAddTeamToBoard() {
        State* state = new State();
        int teamsSize = state->getBoard().getTeams().size();
        
        std::cout << "  Il y a actuellement " << teamsSize << " équipe(s) dans le jeu" << std::endl;
        
        std::cout << "  Ajout d'une équipe au jeu" << std::endl;
        
        Team* team = new Team(1);
        state->getBoard().addTeam(team);
        
        int teamsResize = state->getBoard().getTeams().size();
        std::cout << "  Il y a maintenant " << teamsResize << " équipe(s) dans le jeu" << std::endl;
        
        return (teamsResize == teamsSize + 1);    
    }

    bool unitTest_shouldAddTerrainToBoard() {
        State* state = new State();
        int terrainSize = state->getBoard().getTerrains().size();
        
        std::cout << "  Il y a actuellement " << terrainSize << " terrain(s) dans le jeu" << std::endl;
        
        std::cout << "  Ajout d'un terrain de type HOUSE au jeu" << std::endl;
        
        Terrain* terrain = new House(1, 1, 1);
        state->getBoard().addTerrain(terrain);
        
        terrainSize = state->getBoard().getTerrains().size();
        std::cout << "  Il y a maintenant " << terrainSize << " terrain(s) dans le jeu" << std::endl;
        
        if(terrainSize != 1) {
            return false;
        }
        
        TerrainTypeId terrainType = state->getBoard().getTerrains().at(1)->getTypeId();
        if(terrainType == TerrainTypeId::HOUSE) {
            std::cout << "  Le terrain ajouté est bien de type HOUSE" << std::endl;
        } else {
            return false;
        }
        
        std::cout << "  Ajout d'un terrain de type CASTLE au jeu" << std::endl;
        
        terrain = new Castle(2, 1, 1);
        state->getBoard().addTerrain(terrain);
        
        terrainSize = state->getBoard().getTerrains().size();
        std::cout << "  Il y a maintenant " << terrainSize << " terrain(s) dans le jeu" << std::endl;
                
        if(terrainSize != 2) {
            return false;
        }
        
        terrainType = state->getBoard().getTerrains().at(2)->getTypeId();
        if(terrainType == TerrainTypeId::CASTLE) {
            std::cout << "  Le terrain ajouté est bien de type CASTLE" << std::endl;
            return true;
        } else {
            return false;
        }
    }

    bool unitTest_shouldAddUnitToBoard() {
        State* state = new State();
        int unitSize = state->getBoard().getUnits().size();
        
        std::cout << "  Il y a actuellement " << unitSize << " unité(s) dans le jeu" << std::endl;
        
        std::cout << "  Ajout d'une unité de type SWORDMAN au jeu" << std::endl;
        
        Unit* unit = new Swordman(1, 1, 1);
        state->getBoard().addUnit(unit);
        
        unitSize = state->getBoard().getUnits().size();
        std::cout << "  Il y a maintenant " << unitSize << " unité(s) dans le jeu" << std::endl;
        
        if(unitSize != 1) {
            return false;
        }
        
        UnitTypeId unitType = state->getBoard().getUnits().at(1)->getTypeId();
        if(unitType == UnitTypeId::SWORDMAN) {
            std::cout << "  L'unité ajouté est bien de type SWORDMAN" << std::endl;
        } else {
            return false;
        }
        
        int weaponSize = state->getBoard().getUnits().at(1)->getWeapons().size();
        std::cout << "  L'unité possède " << weaponSize << " arme(s)" << std::endl;
        
        if(weaponSize != 1) {
            return false;
        }        
        
        WeaponTypeId weaponType = state->getBoard().getUnits().at(1)->getWeapons().find(WeaponTypeId::SWORD)->second->getTypeId();
        if(weaponType == WeaponTypeId::SWORD) {
            std::cout << "  L'unité possède bien une arme de type SWORD" << std::endl;
        } else {
            return false;
        }
        
        std::cout << "  Ajout d'une unité de type LEADER au jeu" << std::endl;
        
        unit = new Leader(2, 1, 1);
        state->getBoard().addUnit(unit);
        
        unitSize = state->getBoard().getUnits().size();
        std::cout << "  Il y a maintenant " << unitSize << " unité(s) dans le jeu" << std::endl;
                
        if(unitSize != 2) {
            return false;
        }
        
        unitType = state->getBoard().getUnits().at(2)->getTypeId();
        if(unitType == UnitTypeId::LEADER) {
            std::cout << "  L'unité ajouté est bien de type LEADER" << std::endl;
        } else {
            return false;
        }
        
        weaponSize = state->getBoard().getUnits().at(2)->getWeapons().size();
        std::cout << "  L'unité possède " << weaponSize << " arme(s)" << std::endl;
        
        if(weaponSize != 2) {
            return false;
        }     
        
        weaponType = state->getBoard().getUnits().at(2)->getWeapons().find(WeaponTypeId::SWORD)->second->getTypeId();
        if(weaponType == WeaponTypeId::SWORD) {
            std::cout << "  L'unité possède bien une arme de type SWORD" << std::endl;
        } else {
            return false;
        }
        
        weaponType = state->getBoard().getUnits().at(2)->getWeapons().find(WeaponTypeId::BOW)->second->getTypeId();
        if(weaponType == WeaponTypeId::BOW) {
            std::cout << "  L'unité possède bien une arme de type BOW" << std::endl;
            return true;
        } else {
            return false;
        }
    }

    void unitTest() {
        std::cout << "***************************************************" << std::endl;
        std::cout << "Tentative de création d'un état" << std::endl;

        if(unitTest_shouldCreatState()) {
            std::cout << "Etat créé" << std::endl;
        } else {
            std::cout << "ERREUR : Etat non créé !" << std::endl;
        }
        std::cout << "***************************************************" << std::endl;
        
        std::cout << "Tentative d'ajout d'une équipe au jeu" << std::endl;
        
        if(unitTest_shouldAddTeamToBoard()) {
            std::cout << "Equipe correctement ajoutée au jeu" << std::endl;
        } else {
            std::cout << "ERREUR : Equipe non ajoutée au jeu !" << std::endl;
        }
        std::cout << "***************************************************" << std::endl;

        std::cout << "Tentative d'ajout de terrains au jeu" << std::endl;
        
        if(unitTest_shouldAddTerrainToBoard()) {
            std::cout << "Terrains correctement ajouté au jeu" << std::endl;
        } else {
            std::cout << "ERREUR : L'ajout de terrain au jeu à planté !" << std::endl;
        }
        std::cout << "***************************************************" << std::endl;
        
        std::cout << "Tentative d'ajout d'unités au jeu" << std::endl;
        
        if(unitTest_shouldAddUnitToBoard()) {
            std::cout << "Unités correctement ajouté au jeu" << std::endl;
        } else {
            std::cout << "ERREUR : L'ajout d'unité au jeu à planté !" << std::endl;
        }
        std::cout << "***************************************************" << std::endl;
        
    }

}