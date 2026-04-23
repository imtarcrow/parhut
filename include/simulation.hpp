

class Simulation
{

private:
    long tick_count = 0;

public:
    void init();

    void tick(double delta_time);
    void run();
};
