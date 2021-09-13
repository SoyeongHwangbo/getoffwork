#include <bangtal>
using namespace bangtal;

int main()
{
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	auto workdesk = Scene::create("회사책상", "Images/bgdesk.png");
	auto timer = Timer::create(3.f);

	auto startButton = Object::create("Images/start.png", workdesk, 590, 70);
	auto endButton = Object::create("Images/end.png", workdesk, 590, 20);
	auto restartButton = Object::create("Images/restart.png", workdesk, 590, 70, false);

	auto paper1 = Object::create("Images/1.png", workdesk, 131, 700, false);
	auto paper2 = Object::create("Images/2.png", workdesk, 514, 700, false);
	auto paper3 = Object::create("Images/3.png", workdesk, 897, 700, false);
	auto paper4 = Object::create("Images/4.png", workdesk, 131, 350, false);
	auto paper5 = Object::create("Images/5.png", workdesk, 514, 350, false);
	auto paper6 = Object::create("Images/6.png", workdesk, 879, 350, false);

	startButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action) -> bool{
		//start game
		startButton->hide();
		endButton->hide();
		paper1->show();
		paper2->show();
		paper3->show();
		paper4->show();
		paper5->show();
		paper6->show();
		
		showTimer(timer);
		timer->set(3.f);
		timer->start();

		return true;
	});

	paper1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		object->pick();
		return true;
		});
	paper2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		object->pick();
		return true;
		});
	paper3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		object->pick();
		return true;
		});
	paper4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		object->pick();
		return true;
		});
	paper5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		object->pick();
		return true;
		});
	paper6->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		object->pick();
		return true;
		});

	endButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endGame();
		return true;
		});

	restartButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		startButton->hide();
		endButton->hide();
		paper1->show();
		paper2->show();
		paper3->show();
		paper4->show();
		paper5->show();
		paper6->show();

		showTimer(timer);
		timer->set(3.f);
		timer->start();

		return true;
		});

	timer->setOnTimerCallback([&](TimerPtr timer)->bool {
		startButton->setImage("Images/restart.png");
		startButton->show();
		endButton->show();

		showMessage("야근 당첨!");

		return true;
		});

	startGame(workdesk);

	return 0;
}