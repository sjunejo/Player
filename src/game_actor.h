/*
 * This file is part of EasyRPG Player.
 *
 * EasyRPG Player is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Player is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Player. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _GAME_ACTOR_H_
#define _GAME_ACTOR_H_

// Headers
#include <string>
#include <vector>
#include "rpg_save.h"
#include "game_battler.h"

/**
 * Game_Actor class.
 */
class Game_Actor : public Game_Battler {
public:
	/**
	 * Constructor.
	 *
	 * @param actor_id database actor ID.
	 */
	Game_Actor(int actor_id);

	/**
	 * Sets up the game actor
	 * This is automatically called in the constructor.
	 */
	void Setup();

	/**
	 * Initializes the game actor to the database state.
	 * Sets the skills, HP, SP and experience.
	 */
	void Init();

	/**
	 * Initializes the game actor to the database state
	 * and overwrites them with savedata values.
	 */
	void Init(const RPG::SaveActor& save_data);

	/**
	 * Learns a new skill.
	 *
	 * @param skill_id database skill ID.
	 */
	void LearnSkill(int skill_id);

	/**
	 * Unlearns a skill.
	 *
	 * @param skill_id database skill ID.
	 */
	void UnlearnSkill(int skill_id);

	/**
	 * Checks if the actor has the skill learned.
	 *
	 * @param skill_id ID of skill to check.
	 * @return true if skill has been learned.
	 */
	bool IsSkillLearned(int skill_id);

	/**
	 * Checks if the actor can use the skill.
	 *
	 * @param skill_id ID of skill to check.
	 * @return true if skill can be used.
	 */
	bool IsSkillUsable(int skill_id);

	/**
	 * Gets the actor ID.
	 *
	 * @return Actor ID
	 */
	int GetId() const;

	/**
	 * Calculates the Exp needed for a level up.
	 *
	 * @param level level to calculate exp for.
	 * @todo Add Formula for RPG2k3.
	 * @return Needed experience.
	 */
	int CalculateExp(int level);

	/**
	 * Calculates the Experience curve for every level.
	 */
	void MakeExpList();

	/**
	 * Converts the currect Exp to a string.
	 *
	 * @return Exp-String or ------ if Level is max.
	 */
	std::string GetExpString();

	/**
	 * Converts the Exp for the next LV to a string.
	 *
	 * @return Exp-String or ------ if Level is max.
	 */
	std::string GetNextExpString();

	/**
	 * Gets actor name.
	 *
	 * @return name.
	 */
	std::string GetName() const;

	/**
	 * Gets actor character graphic filename.
	 *
	 * @return character graphic filename.
	 */
	std::string GetCharacterName() const;

	/**
	 * Gets actor character graphic index.
	 *
	 * @return character graphic index.
	 */
	int GetCharacterIndex() const;

	/**
	 * Gets actor face graphic filename.
	 *
	 * @return face graphic filename.
	 */
	std::string GetFaceName() const;

	/**
	 * Gets actor face graphic index.
	 *
	 * @return face graphic index.
	 */
	int GetFaceIndex() const;

	/**
	 * Gets actor title.
	 *
	 * @return title.
	 */
	std::string GetTitle() const;

	/**
	 * Gets actor equipped weapon ID.
	 *
	 * @return equipped weapon ID.
	 */
	int GetWeaponId() const;

	/**
	 * Gets actor equipped shield ID.
	 *
	 * @return equipped shield ID.
	 */
	int GetShieldId() const;

	/**
	 * Gets actor equipped armor ID.
	 *
	 * @return equipped armor ID.
	 */
	int GetArmorId() const;

	/**
	 * Gets actor equipped helmet ID.
	 *
	 * @return equipped helmet ID.
	 */
	int GetHelmetId() const;

	/**
	 * Gets actor equipped accesory ID.
	 *
	 * @return equipped accessory ID.
	 */
	int GetAccessoryId() const;

	/**
	 * Gets actor current level.
	 *
	 * @return current level.
	 */
	int GetLevel() const;

	/**
	* Gets actor current experience points.
	*
	* @return current experience points.
	*/
	int GetExp() const;

	/**
	 * Sets exp of actor.
	 *
	 * @param _exp exp to set.
	 */
	void SetExp(int _exp);

	/**
	 * Changes exp of actor.
	 *
	 * @param exp new exp.
	 */
	void ChangeExp(int exp);

	/**
	 * Changes level of actor.
	 *
	 * @param level new level.
	 */
	void ChangeLevel(int level);

	/**
	 * Sets level of actor.
	 *
	 * @param _level level to set.
	 */
	void SetLevel(int _level);

	/**
	 * Checks if the actor can equip the item.
	 *
	 * @param item_id ID of item to check.
	 * @return true if it can equip the item.
	 */
	bool IsEquippable(int item_id);

	/**
	 * Sets face graphic of actor.
	 * @param file_name file containing new face.
	 * @param index index of face graphic in the file.
	 */
	void SetFace(const std::string& file_name, int index);

	/**
	 * Gets the equipped equipment based on the type.
	 * @param equip_type type of equipment.
	 * @return item_id or 0 if no equipment or -1 if invalid.
	 */
	int GetEquipment(int equip_type) const;

	/**
	 * Sets the equipment based on the type.
	 *
	 * @param equip_type type of equipment.
	 * @param new_item_id item to equip.
	 * @return item_id of old item, or 0 if no equipment or -1 if invalid.
	 */
	int SetEquipment(int equip_type, int new_item_id);

	/**
	 * Changes the equipment of the actor.
	 * Removes one instance of that item from the Inventory.
	 * and adds the old one of the actor to it.
	 * If you don't want this use SetEquipment instead.
	 *
	 * @param equip_type type of equipment.
	 * @param item_id item to equip.
	 */
	void ChangeEquipment(int equip_type, int item_id);

	/**
	 * Gets learned skills list.
	 *
	 * @return learned skills list.
	 */
	const std::vector<int16_t>& GetSkills() const;

	/**
	 * Gets actor states list.
	 *
	 * @return vector containing the IDs of all states the actor has.
	 */
	const std::vector<int16_t>& GetStates() const;
	std::vector<int16_t>& GetStates();

	int GetHp() const;
	void SetHp(int _hp);

	int GetSp() const;
	void SetSp(int _sp);

	/**
	 * Gets the max HP for the current level.
	 *
	 * @param mod include the modifier bonus.
	 */
	int GetBaseMaxHp(bool mod) const;

	/**
	 * Gets the max SP for the current level.
	 *
	 * @param mod include the modifier bonus.
	 */
	int GetBaseMaxSp(bool mod) const;

	/**
	 * Gets the attack for the current level.
	 *
	 * @param mod include the modifier bonus.
	 * @param equip include the equipment bonuses.
	 */
	int GetBaseAtk(bool mod, bool equip) const;

	/**
	 * Gets the defense for the current level.
	 *
	 * @param mod include the modifier bonus.
	 * @param equip include the equipment bonuses.
	 */
	int GetBaseDef(bool mod, bool equip) const;

	/**
	 * Gets the spirit for the current level.
	 *
	 * @param mod include the modifier bonus.
	 * @param equip include the equipment bonuses.
	 */
	int GetBaseSpi(bool mod, bool equip) const;

	/**
	 * Gets the agility for the current level.
	 *
	 * @param mod include the modifier bonus.
	 * @param equip include the equipment bonuses.
	 */
	int GetBaseAgi(bool mod, bool equip) const;

	/**
	 * Gets the max HP for the current level.
	 * Modifier and equipment bonuses are included.
	 */
	int GetBaseMaxHp() const;

	/**
	 * Gets the max SP for the current level.
	 * Modifier and equipment bonuses are included.
	 */
	int GetBaseMaxSp() const;

	/**
	 * Gets the attack for the current level.
	 * Modifier and equipment bonuses are included.
	 */
	int GetBaseAtk() const;

	/**
	 * Gets the defense for the current level.
	 * Modifier and equipment bonuses are included.
	 */
	int GetBaseDef() const;

	/**
	 * Gets the spirit for the current level.
	 * Modifier and equipment bonuses are included.
	 */
	int GetBaseSpi() const;

	/**
	 * Gets the agility for the current level.
	 * Modifier and equipment bonuses are included.
	 */
	int GetBaseAgi() const;

	/**
	 * Sets the base max HP by adjusting the modifier bonus.
	 * The existing modifier bonus and equipment bonuses
	 * are taken into account.
	 *
	 * @param _maxhp max HP.
	 */
	void SetBaseMaxHp(int _maxhp);

	/**
	 * Sets the base max SP by adjusting the modifier bonus.
	 * The existing modifier bonus and equipment bonuses
	 * are taken into account.
	 *
	 * @param _maxsp max SP.
	 */
	void SetBaseMaxSp(int _maxsp);

	/**
	 * Sets the base attack by adjusting the modifier bonus.
	 * The existing modifier bonus and equipment bonuses
	 * are taken into account.
	 *
	 * @param _atk attack.
	 */
	void SetBaseAtk(int _atk);

	/**
	 * Sets the base defense by adjusting the modifier bonus.
	 * The existing modifier bonus and equipment bonuses
	 * are taken into account.
	 *
	 * @param _def defense.
	 */
	void SetBaseDef(int _def);

	/**
	 * Sets the base spirit by adjusting the modifier bonus.
	 * The existing modifier bonus and equipment bonuses
	 * are taken into account.
	 *
	 * @param _spi spirit.
	 */
	void SetBaseSpi(int _spi);

	/**
	 * Sets the base agility by adjusting the modifier bonus.
	 * The existing modifier bonus and equipment bonuses
	 * are taken into account.
	 *
	 * @param _agi agility.
	 */
	void SetBaseAgi(int _agi);

	/**
	 * Gets if actor has two weapons.
	 *
	 * @return true if actor has two weapons.
	 */
	bool GetTwoSwordsStyle() const;

	/**
	 * Sets new actor name.
	 *
	 * @param new_name new name.
	 */
	void SetName(const std::string &new_name);

	/**
	 * Sets new actor title.
	 *
	 * @param new_title new title.
	 */
	void SetTitle(const std::string &new_title);

	/**
	 * Sets actor sprite.
	 *
	 * @param file graphic file.
	 * @param index graphic index.
	 * @param transparent transparent flag.
	 */
	void SetSprite(const std::string &file, int index, bool transparent);

	/**
	 * Changes battle commands.
	 *
	 * @param add true => add the command, false => remove the command.
	 * @param id command to add/remove, 0 to remove all commands.
	 */
	void ChangeBattleCommands(bool add, int id);

	/**
	 * Gets Rpg2k3 hero class.
	 *
	 * @return Rpg2k3 hero class.
	 */
	int GetClass() const;
	/**
	 * Sets new Rpg2k3 hero class.
	 *
	 * @param class_id mew Rpg2k3 hero class.
	 */
	void SetClass(int class_id);

	/**
	 * Gets battle commands.
	 *
	 * @return all Rpg2k3 battle commands.
	 */
	const std::vector<uint32_t>& GetBattleCommands();

	/**
	 * Gets battle row for Rpg2k3 battles.
	 *
	 * @return row for Rpg2k3 battles (-1 back, 1 front).
	 */
	int GetBattleRow() const;
	/**
	 * Sets battle row for Rpg2k3 battles.
	 *
	 * @param battle_row new row for Rpg2k3 battles (-1 back, 1 front).
	 */
	void SetBattleRow(int battle_row);

private:
	RPG::SaveActor& data;

	std::vector<int> exp_list;
};

#endif
