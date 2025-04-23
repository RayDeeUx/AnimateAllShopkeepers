#include <Geode/modify/GJShopLayer.hpp>

using namespace geode::prelude;

class $modify(MyGJShopLayer, GJShopLayer) {
	virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) {
		bool result = GJShopLayer::ccTouchBegan(touch, event);
		if (!result) return false;
		if (!m_shopKeeper || !touch || !event) return true;

		auto location = touch->getLocation();
		auto worldSpace = m_shopKeeper->convertToNodeSpace(location);
		
		return true;
	}
};

/*
bool __thiscall GJShopLayer::ccTouchBegan(GJShopLayer *this,CCTouch *param_1,CCEvent *param_2)

{
  float fVar1;
  AnimatedShopKeeper *this_00;
  bool bVar2;
  CCPoint *pCVar3;
  longlong lVar4;
  float *pfVar5;
  void *pvVar6;
  CCPoint local_res8 [8];
  string_data_union *local_res20;
  CCRect local_50 [16];
  string_data_union local_40;
  undefined8 local_30;
  undefined8 local_28;
  
  if (*(int *)(this + 0x88) != 0) {
    return false;
  }
  cocos2d::CCTouch::getLocation((CCTouch *)param_1);
  pCVar3 = (CCPoint *)
           cocos2d::CCNode::convertToNodeSpace((CCNode *)(this + -0x140),(CCPoint *)&local_res20);
  cocos2d::CCPoint::operator=(local_res8,pCVar3);
  lVar4 = (**(code **)(**(longlong **)(this + 200) + 200))();
  fVar1 = *(float *)(lVar4 + 4);
  pfVar5 = (float *)(**(code **)(**(longlong **)(this + 200) + 200))();
  cocos2d::CCRect::CCRect(local_50,*pfVar5 - 40.0,(fVar1 - 45.0) + 10.0,80.0,90.0);
  bVar2 = cocos2d::CCRect::containsPoint(local_50,local_res8);
  if (!bVar2) {
    return true;
  }
  if (*(char *)(*(longlong *)(this + 200) + 0x2f5) != '\0') {
    return true;
  }
  if (DAT_1406a4e68 == (GameManager *)0x0) {
    local_res20 = (string_data_union *)operator_new(0x668);
    DAT_1406a4e68 = (GameManager *)FUN_140177af0(local_res20);
    (**(code **)(*(longlong *)DAT_1406a4e68 + 0x48))(DAT_1406a4e68);
  }
  bVar2 = GameManager::getUGV(DAT_1406a4e68,"31");
  if (bVar2) {
    local_res20 = &local_40;
    local_40._8_8_ = 0;
    local_30 = 4;
    local_28 = 0xf;
    local_40.ptr = (char *)0x32323030;
    if (DAT_1406a4e78 == (GameStatsManager *)0x0) {
      pvVar6 = operator_new(0x3d8);
      DAT_1406a4e78 = (GameStatsManager *)FUN_1401cdb10(pvVar6);
      (**(code **)(*(longlong *)DAT_1406a4e78 + 0x48))(DAT_1406a4e78);
    }
    bVar2 = GameStatsManager::isSpecialChestUnlocked(DAT_1406a4e78,(string *)&local_40);
    if (!bVar2) {
      bVar2 = true;
      goto LAB_1402a7462;
    }
  }
  bVar2 = false;
LAB_1402a7462:
  this_00 = *(AnimatedShopKeeper **)(this + 200);
  if ((4 < *(int *)(this_00 + 0x2f8)) || (bVar2)) {
    *(undefined4 *)(this_00 + 0x2f8) = 2;
    showReactMessage(this + -0x140);
    if (*(int *)(this + 0xd0) == 9) {
      *(undefined4 *)(*(longlong *)(this + 200) + 0x2f8) = 0;
    }
  }
  else {
    AnimatedShopKeeper::playReactAnimation(this_00);
  }
  return true;
}
*/