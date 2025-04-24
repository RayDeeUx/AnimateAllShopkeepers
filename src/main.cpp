#include <Geode/modify/GJShopLayer.hpp>

using namespace geode::prelude;

constexpr auto dummyRectNoAnchor = cocos2d::CCRect{310, 190, 90, 80};
// 356, 230, 90, 80 WITH ANCHOR AT 0.5 0.5
// 310, 190, 90, 80 WITH ANCHOR AT 0.0 0.0

class $modify(MyGJShopLayer, GJShopLayer) {
	virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) {
		bool result = GJShopLayer::ccTouchBegan(touch, event);
		if (!result && this->m_type == ShopType::Normal) return false;
		if (!m_shopKeeper || !touch || !event || this->m_type == ShopType::Normal) return true;

		const auto location = touch->getLocation();
		log::info("location: {}", location);
		if (!dummyRectNoAnchor.containsPoint(location)) return true;

		m_shopKeeper->startAnimating();
		return true;
	}
};