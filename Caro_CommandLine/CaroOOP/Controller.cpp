#include "Controller.h"

void Controller::controller() {
	while (!isGameOver)
	{
		m.getBoard().plotBoard();
		m.update();
		isGameOver = m.checkWin(draw);

		if (isGameOver == true)
		{
			if (draw == true) {
				cout << "-----GAME DRAW-----";
				m.getPlayer1().raiseDraw();
				m.getPlayer2().raiseDraw();
				d.saveData(m.getPlayer1().getName(), m.getPlayer1().getWin(), m.getPlayer1().getDraw(), m.getPlayer1().getLose());
				d.saveData(m.getPlayer2().getName(), m.getPlayer2().getWin(), m.getPlayer2().getDraw(), m.getPlayer2().getLose());
			}
			else {
				cout << "-----Player " <<--m.ID << " is " << m.NAME << " is winner-----" << endl;
				if (m.NAME == m.getPlayer1().getName()) {
					m.getPlayer1().raiseWin();
					m.getPlayer2().raiseLose();

					d.saveData(m.getPlayer1().getName(), m.getPlayer1().getWin(), m.getPlayer1().getDraw(),m.getPlayer1().getLose());
					d.saveData(m.getPlayer2().getName(), m.getPlayer2().getWin(), m.getPlayer2().getDraw(), m.getPlayer2().getLose());
				}
				else {
					m.getPlayer2().raiseWin();
					m.getPlayer1().raiseLose();
					d.saveData(m.getPlayer1().getName(), m.getPlayer1().getWin(), m.getPlayer1().getDraw(), m.getPlayer1().getLose());
					d.saveData(m.getPlayer2().getName(), m.getPlayer2().getWin(), m.getPlayer2().getDraw(), m.getPlayer2().getLose());
				}
			}
		}
	}
}
Match& Controller::getMatch() {
	return m;
}
