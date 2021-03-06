/////////////////////////////////////////////////////////////////// /////////////////////////////////////////
// (C) Gamer Camp / Alex Darby 2018
// Distributed under the MIT license - see readme.md
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _GAMELAYERSPACEINVADERS_H_
#define _GAMELAYERSPACEINVADERS_H_

#include "../GCCocosInterface/IGCGameLayer.h"
#include "ImpossibleRescue/Player/CPlayer.h"
#include "ImpossibleRescue/Audio/ISoundEffect.h"

#ifndef _GCLEVELLOADER_OGMO_H_
	#include "../GCCocosInterface/LevelLoader/GCLevelLoader_Ogmo.h"
#endif

//////////////////////////////////////////////////////////////////////////
// fwd decl
class CGCObjSprite;
class CGCObjPlayer;
class CGCObjPlatform;
class CGCObjGroupPlatform;
class CGCObjItem;
class CGCObjGroupItem;
class CGCObjInvader;
class CGCObjGroupInvader;
class CGCObjGroupProjectilePlayer;
class CLevelTimer;
class CTurretProjectileGroup;

class CPlayerPrimaryProjectileGroup;
class CPlayerSecondaryProjectileGroup;
class CMovingPlatform3m;

class CLabelHelper;

//////////////////////////////////////////////////////////////////////////
// sample class that creates a 'game' by deriving from IGCGameLayer
//////////////////////////////////////////////////////////////////////////
class CGCGameLayerPlatformer 
: public IGCGameLayer
, public b2ContactListener 
{
private:
	// object groups
	CGCObjGroupPlatform*			m_pcGCGroupPlatform;
	CGCObjGroupItem*				m_pcGCGroupItem;
	CGCObjGroupInvader*				m_pcGCGroupInvader;
	CGCObjGroupProjectilePlayer*	m_pcGCGroupProjectilePlayer;

	CPlayerPrimaryProjectileGroup*		m_pcPlayerPrimaryProjectileGroup;
	CPlayerSecondaryProjectileGroup*	m_pcPlayerSecondaryProjectileGroup;
	CTurretProjectileGroup*				m_pcTurretProjectileGroup;

	// backgrounds
	CGCObjSprite*					m_pcGCSprBackGround;

	// Player
	CPlayer*				m_pcCPlayer;
	CHackingStation*		m_pcHackingStation1;
	CHackingStation*		m_pcHackingStation2;
	CGCFactoryCreationParams	m_sPlayerCreateParams;

	// level loader
	CGCLevelLoader_Ogmo		m_cLevelLoader;

	// level timer
	CLevelTimer*			m_pcLevelTimer;

	CLabelHelper*			m_pcPlayerHealthLabel;
	
public:
	CGCGameLayerPlatformer	( void );
	~CGCGameLayerPlatformer	( void );

	//////////////////////////////////////////////////////////////////////////
	// player actions 
	enum EPlayerActions
	{
		EPA_Up = 0,
		EPA_Down,
		EPA_Left,
		EPA_Right,
		EPA_Fire
	};
	// player actions 
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
    // 'selector' callbacks for menu buttons
    void Callback_OnQuitButton	( Ref* pSender );
    void Callback_OnResetButton	( Ref* pSender );

	// called from VOnUpdate
	void HandleCollisions( void );

	//////////////////////////////////////////////////////////////////////////
	// CCNode interface...
	virtual void onEnter();
	// CCNode interface...
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	// IGCGameLayer interface

		virtual	void VOnCreate	( void );
		virtual void VOnUpdate	( f32 fTimeStep );
		virtual	void VOnDestroy ( void );	

	// IGCGameLayer interface
	//////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////
	// b2ContactListener interface - see b2ContactListener for details of 
	// when these get called and what they are

		virtual void BeginContact	( b2Contact* pB2Contact );
		virtual void EndContact		( b2Contact* pB2Contact );
		virtual void PreSolve		( b2Contact* pB2Contact, const b2Manifold* pOldManifold );
		virtual void PostSolve		( b2Contact* pB2Contact, const b2ContactImpulse* pImpulse );

	// b2ContactListener interface - see b2ContactListener for details of 
	// when these get called and what they are
	//////////////////////////////////////////////////////////////////////////
	
	////////////////////////////////////////////////////////////////////////// 
	// reset handling
private:
	bool							m_bResetWasRequested;

	ISoundEffect* m_psfxGameMusic;

	void RequestReset()
	{
		m_bResetWasRequested = true;
	}

	void ResetRequestWasHandled()
	{
		m_bResetWasRequested = false; 
	}

	bool ResetWasRequested()
	{
		return m_bResetWasRequested; 
	}
};

#endif // __CGCGameLayerPlatformer_SCENE_H__
