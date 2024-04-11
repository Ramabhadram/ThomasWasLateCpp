#include "Engine.h"

void Engine::draw()
{
	// Rub out the last frame;
	m_Window.clear(Color::White);

	if (!m_SplitScreen)
	{
		// Switch to background view;
		m_Window.setView(m_BGMainView);
		// Draw the Background;
		m_Window.draw(m_BackgroundSprite);
		// Switch to Main View;
		m_Window.setView(m_MainView);

		// Draw the Level;
		m_Window.draw(m_VALevel, &m_TextureTiles);

		// Draw Thomas;
		m_Window.draw(m_Thomas.getSprite());
		// Draw Bob;
		m_Window.draw(m_Bob.getSprite());
	}
	else
	{
		// Split Screen View is active;
		// First Draw  Thomas' Side of the screen;
		// Switch to Background view;
		m_Window.setView(m_BGLeftView);
		// Draw the Background;
		m_Window.draw(m_BackgroundSprite);
		// Switch to m_LeftView;
		m_Window.setView(m_LeftView);

		// Draw the Level;
		m_Window.draw(m_VALevel, &m_TextureTiles);
		
		// Draw Bob;
		m_Window.draw(m_Bob.getSprite());
		// Draw Thomas;
		m_Window.draw(m_Thomas.getSprite());

		// Now draw Bob's side of the screen;

		// Switch to background view;
		m_Window.setView(m_BGRightView);
		// Draw the Background;
		m_Window.draw(m_BackgroundSprite);
		// Switch to m_RightView;
		m_Window.setView(m_RightView);

		// Draw the Level;
		m_Window.draw(m_VALevel, &m_TextureTiles);

		// Draw Thomas;
		m_Window.draw(m_Thomas.getSprite());
		// Draw Bob;
		m_Window.draw(m_Bob.getSprite());
	}

	// Draw the HUD;
	// Switch to m_HudView;
	m_Window.setView(m_HudView);

	// Show everything we have just drawn;
	m_Window.display();
}