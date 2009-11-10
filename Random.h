#pragma once

namespace IRL
{
    // Simple linear congruential generator
    class Random
    {
    public:
        explicit Random(uint32_t seed = 0) : _state(seed)
        { }

        void Seed(uint32_t seed) 
        {
            _state = seed;
        }

        template<class T>
        const T Uniform(const T min, const T max)
        {
            return (T)(Next() * (max - min) / m + min);
        }

        template<class T>
        const T Uniform(const T max)
        {
            return (T)(Next() * max / m);
        }

    private:
        static const uint32_t a = 214013L;
        static const uint32_t c = 2531011L;
        static const uint32_t m = 0x7fff;

        inline uint32_t Next()
        {
            _state = _state * a + c;
            return (_state >> 16) & m;
        }

        uint32_t _state;
    };
}