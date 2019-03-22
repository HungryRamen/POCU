#include "Game.h"
namespace lab9
{
	Game::Game(unsigned int seed,unsigned int poolsize):
		mPoolSize(poolsize),
		mObjectPoolIceCube(poolsize)
	{
		srand(seed);
	}

	Game::~Game()
	{
		for (auto it = mActiveGameObjects.begin(); it != mActiveGameObjects.end(); ++it)
		{
			delete (*it);
		}

		mActiveGameObjects.clear();
	}

	void Game::Spawn()
	{
		IceCube* iceCube = mObjectPoolIceCube.Get();
		iceCube->Initialize(rand() % MAX_FRAME_COUNT_TO_LIVE + 1);
		mActiveGameObjects.push_back(iceCube);
	}

	void Game::Update()
	{
		for (auto it = mActiveGameObjects.begin(); it != mActiveGameObjects.end();)
		{
			IceCube* iceCube = *it;
			iceCube->Animate();

			if (!iceCube->IsActive())
			{
				mObjectPoolIceCube.Return(iceCube);
				it = mActiveGameObjects.erase(it);
				continue;
			}

			++it;
		}
	}

	const std::vector<IceCube*>& Game::GetActiveGameObjects() const
	{
		return mActiveGameObjects;
	}
	const ObjectPool<IceCube>& Game::GetObjectPool() const
	{
		return mObjectPoolIceCube;
	}
}