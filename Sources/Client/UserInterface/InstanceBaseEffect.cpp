/// 1.
// Search
void CInstanceBase::__SetAffect(UINT eAffect, bool isVisible)

// Add above
#if defined(ENABLE_SOUL_SYSTEM)
void CInstanceBase::__SetSoulAffect(UINT eAffect, bool isVisible)
{
	if (eAffect != AFFECT_SOUL_RED && eAffect != AFFECT_SOUL_BLUE && eAffect != AFFECT_SOUL_MIX)
		return;

	D3DXVECTOR3 v3EffectPosition(0.0f, 0.0f, 30.0f);

	if (IsMountingHorse())
	{
		CActorInstance* pHorseActor = m_kHorse.GetActorPtr();
		if (pHorseActor)
		{
			m_kHorse.Deform();

			int iBoneIndex = 0;
			if (pHorseActor->FindBoneIndex(CRaceData::PART_MAIN, "saddle", &iBoneIndex))
			{
				D3DXMATRIX* pBoneMat;
				if (pHorseActor->GetBoneMatrix(CRaceData::PART_MAIN, iBoneIndex, &pBoneMat))
					v3EffectPosition.z = pBoneMat->_43;
			}
		}
	}

	if (isVisible)
	{
		if (!m_adwCRCAffectEffect[eAffect])
			m_adwCRCAffectEffect[eAffect] = m_GraphicThingInstance.AttachEffectByID(0, NULL, ms_adwCRCAffectEffect[EFFECT_AFFECT + eAffect], &v3EffectPosition);
	}
	else if (m_adwCRCAffectEffect[eAffect])
	{
		CInstanceBase::__DetachEffect(m_adwCRCAffectEffect[eAffect]);
		m_adwCRCAffectEffect[eAffect] = 0;
	}
}
#endif

/// 2.
// Search
		case AFFECT_STUN:
			m_GraphicThingInstance.SetSleep(isVisible);
			break;

// Add below
#if defined(ENABLE_SOUL_SYSTEM)
		case AFFECT_SOUL_RED:
		case AFFECT_SOUL_BLUE:
		case AFFECT_SOUL_MIX:
			__SetSoulAffect(eAffect, isVisible);
			return;
#endif
