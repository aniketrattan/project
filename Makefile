graphics: main.cpp AssetManager.cpp EncounterState.cpp GameGraphic.cpp StateMachine.cpp NumDisplay.cpp MenuDisplay.cpp ActionPoints.cpp MapState.cpp CampsiteState.cpp ShopState.cpp
	@g++ main.cpp AssetManager.cpp EncounterState.cpp GameGraphic.cpp StateMachine.cpp NumDisplay.cpp MenuDisplay.cpp ActionPoints.cpp MapState.cpp CampsiteState.cpp ShopState.cpp -o graph -lsfml-graphics -lsfml-window -lsfml-system
	@make run

build: main.cpp AssetManager.cpp EncounterState.cpp GameGraphic.cpp StateMachine.cpp NumDisplay.cpp MenuDisplay.cpp ActionPoints.cpp MapState.cpp CampsiteState.cpp ShopState.cpp Character.cpp Fighter.cpp Wizard.cpp Cleric.cpp Minion.cpp MiniBoss.cpp Boss.cpp Game.cpp
	@g++ main.cpp AssetManager.cpp EncounterState.cpp GameGraphic.cpp StateMachine.cpp NumDisplay.cpp MenuDisplay.cpp ActionPoints.cpp MapState.cpp CampsiteState.cpp ShopState.cpp Character.cpp Fighter.cpp Wizard.cpp Cleric.cpp Minion.cpp MiniBoss.cpp Boss.cpp Game.cpp -o prog -lsfml-graphics -lsfml-window -lsfml-system
	@make run

run:
	@./graph

everything:
	@./prog





