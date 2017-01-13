namespace Game
{
#ifndef PICKUP_H
#define PICKUP_H


class Pickup
{
    public:
        Pickup();
        virtual ~Pickup();
        int X,Y,Type;
        bool operator==(const Game::Pickup& other) const
	{
		if (X == other.X&&Y == other.Y&&Type == other.Type)
		{
			return true;
		}
		return false;
	}

    protected:

    private:
};

#endif // PICKUP_H
}
