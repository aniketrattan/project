build: main.cpp AssetManager.cpp EncounterState.cpp GameGraphic.cpp StateMachine.cpp NumDisplay.cpp Items.cpp Shop.cpp MenuDisplay.cpp ActionPoints.cpp MapState.cpp CampsiteState.cpp ShopState.cpp Character.cpp Fighter.cpp Wizard.cpp Cleric.cpp Minion.cpp MiniBoss.cpp Boss.cpp Game.cpp DescriptionDisplay.cpp ShopUpper.cpp Save1.cpp
	@g++ main.cpp AssetManager.cpp EncounterState.cpp GameGraphic.cpp StateMachine.cpp NumDisplay.cpp Items.cpp Shop.cpp MenuDisplay.cpp ActionPoints.cpp MapState.cpp CampsiteState.cpp ShopState.cpp Character.cpp Fighter.cpp Wizard.cpp Cleric.cpp Minion.cpp MiniBoss.cpp Boss.cpp Game.cpp DescriptionDisplay.cpp ShopUpper.cpp Save1.cpp -o prog -lsfml-graphics -lsfml-window -lsfml-system
	@make run
run:
	@./prog