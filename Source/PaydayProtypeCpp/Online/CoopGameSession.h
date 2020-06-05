// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameSession.h"
#include "Online.h"
#include "CoopGameSession.generated.h"

/**
 * 
 */
UCLASS()
class PAYDAYPROTYPECPP_API ACoopGameSession : public AGameSession
{
	GENERATED_BODY()

	// Game Session Settings
	TSharedPtr<FOnlineSessionSearch> SearchSettings;
	TSharedPtr<FOnlineSessionSettings> HostSettings;

	// Create Session Handler & Delegate
	FDelegateHandle OnCreateSessionCompleteDelegateHandle;
	FOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate;
	
	FDelegateHandle OnStartSessionCompleteDelegateHandle;
	FOnStartSessionCompleteDelegate OnStartSessionCompleteDelegate;
	
	FDelegateHandle OnDestroySessionCompleteDelegateHandle;
	FOnDestroySessionCompleteDelegate OnDestroySessionCompleteDelegate;
	
	// Find Session Handler & Delegate
	FDelegateHandle OnFindSessionsCompleteDelegateHandle;
	FOnFindSessionsCompleteDelegate OnFindSessionsCompleteDelegate;
	
	FDelegateHandle OnFindFriendSessionCompleteDelegateHandle;
	FOnFindFriendSessionCompleteDelegate OnFindFriendSessionCompleteDelegate;

	// Join Session Handler & Delegate
	FDelegateHandle OnJoinSessionCompleteDelegateHandle;
	FOnJoinSessionCompleteDelegate OnJoinSessionCompleteDelegate;
	
public:

	// Constructor
	ACoopGameSession();

	/*
	 * Session Manager Interfaces
	 */
	void CreateRoom( int32 HostingPlayerId );
	void FindRooms();
	void JoinRoom();

	/*
	 * Session Callbacks
	 */
	void OnCreateSessionComplete( FName strSessionName, bool bWasSuccessful );
	void OnFindSessionsComplete( bool bWasSuccessful );
};