""" 1. """
# Search
def __LoadGameWarrior():

# Add above
# Make sure it's inside the __LoadGameEffect function
	if app.ENABLE_SOUL_SYSTEM:
		chrmgr.RegisterEffect(chrmgr.EFFECT_AFFECT + chr.AFFECT_SOUL_RED, "", "d:/ymir work/effect/etc/soul/soul_red_001.mse")
		chrmgr.RegisterEffect(chrmgr.EFFECT_AFFECT + chr.AFFECT_SOUL_BLUE, "", "d:/ymir work/effect/etc/soul/soul_blue_001.mse")
		chrmgr.RegisterEffect(chrmgr.EFFECT_AFFECT + chr.AFFECT_SOUL_MIX, "", "d:/ymir work/effect/etc/soul/soul_mix_001.mse")
