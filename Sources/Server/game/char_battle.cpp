/// 1.
// Search
			default:
				sys_err("Unhandled battle type %d", GetMobBattleType());
				iRet = BATTLE_NONE;
				break;
		}

// Add below
#if defined(__SOUL_SYSTEM__)
		if (iRet != BATTLE_NONE)
			SoulItemProcess(RED_SOUL);
#endif

/// 2.
// Search
		sys_log(1, "Attack call ComputeSkill %d %s", bType, pkVictim ? pkVictim->GetName() : "");
		iRet = ComputeSkill(bType, pkVictim);

// Add below
#if defined(__SOUL_SYSTEM__)
		if (iRet != BATTLE_NONE)
			SoulItemProcess(BLUE_SOUL);
#endif

/// 3.
// Search
		case DAMAGE_TYPE_NORMAL:
		case DAMAGE_TYPE_NORMAL_RANGE:
		{
			if (pAttacker)
			{
				if (pAttacker->GetPoint(POINT_NORMAL_HIT_DAMAGE_BONUS))
					dam = dam * (100 + pAttacker->GetPoint(POINT_NORMAL_HIT_DAMAGE_BONUS)) / 100;
			}

			dam = dam * (100 - MIN(99, GetPoint(POINT_NORMAL_HIT_DEFEND_BONUS))) / 100;
		}
		break;

// Replace with
		case DAMAGE_TYPE_NORMAL:
		case DAMAGE_TYPE_NORMAL_RANGE:
		{
			if (pAttacker)
			{
				if (pAttacker->GetPoint(POINT_NORMAL_HIT_DAMAGE_BONUS))
					dam = dam * (100 + pAttacker->GetPoint(POINT_NORMAL_HIT_DAMAGE_BONUS)) / 100;

#if defined(__SOUL_SYSTEM__)
				if (pAttacker->FindAffect(AFFECT_SOUL, AFF_SOUL_RED))
					dam = dam * (100 + pAttacker->GetSoulDamage(RED_SOUL)) / 100;
#endif
			}

			dam = dam * (100 - MIN(99, GetPoint(POINT_NORMAL_HIT_DEFEND_BONUS))) / 100;
		}
		break;

/// 4.
// Search
		case DAMAGE_TYPE_MELEE:
		case DAMAGE_TYPE_RANGE:
		case DAMAGE_TYPE_FIRE:
		case DAMAGE_TYPE_ICE:
		case DAMAGE_TYPE_ELEC:
		case DAMAGE_TYPE_MAGIC:
		//case DAMAGE_TYPE_EARTH:
		{
			if (pAttacker)
			{
				if (pAttacker->GetPoint(POINT_SKILL_DAMAGE_BONUS))
					dam = dam * (100 + pAttacker->GetPoint(POINT_SKILL_DAMAGE_BONUS)) / 100;
			}

			dam = dam * (100 - MIN(99, GetPoint(POINT_SKILL_DEFEND_BONUS))) / 100;
		}
		break;

// Replace with
		case DAMAGE_TYPE_MELEE:
		case DAMAGE_TYPE_RANGE:
		case DAMAGE_TYPE_FIRE:
		case DAMAGE_TYPE_ICE:
		case DAMAGE_TYPE_ELEC:
		case DAMAGE_TYPE_MAGIC:
		//case DAMAGE_TYPE_EARTH:
		{
			if (pAttacker)
			{
				if (pAttacker->GetPoint(POINT_SKILL_DAMAGE_BONUS))
					dam = dam * (100 + pAttacker->GetPoint(POINT_SKILL_DAMAGE_BONUS)) / 100;

#if defined(__SOUL_SYSTEM__)
				if (pAttacker->FindAffect(AFFECT_SOUL, AFF_SOUL_BLUE))
					dam = dam * (100 + pAttacker->GetSoulDamage(BLUE_SOUL)) / 100;
#endif
			}

			dam = dam * (100 - MIN(99, GetPoint(POINT_SKILL_DEFEND_BONUS))) / 100;
		}
		break;
