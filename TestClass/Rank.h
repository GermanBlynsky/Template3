#pragma once
#include <iostream>
namespace uizi {
    enum Rank_ { NoRank = 0, CandidatRank = 1, DoctorRank = 2 };
    class Rank
    {
        Rank_ rank;
    public:
        Rank(Rank_ rank);
        std::string toString() const;
        void setRank(Rank_ rank);
        friend std::istream& operator>>(std::istream& is, Rank& rank) {
            std::string rankStr;
            is >> rankStr;
            if (rankStr == "Norank") {
                rank.setRank(NoRank);
                return is;
            }
            if (rankStr == "Candidat") {
                rank.setRank(CandidatRank);
                return is;
            }
            if (rankStr == "Doctor") {
                rank.setRank(DoctorRank);
                return is;
            }
        }
        friend std::ostream& operator<<(std::ostream& os, const Rank& rank) {
            os << rank.toString();
            return os;
        }
        friend bool operator==(const Rank& r1, const Rank& r2) {
            return r1.rank == r2.rank;
        }
        Rank();
    };
}