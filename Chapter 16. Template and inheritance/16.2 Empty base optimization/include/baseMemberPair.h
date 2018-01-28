#ifndef BASE_MENBER_PAIR_H_
#define BASE_MENBER_PAIR_H_

template <typename Base, typename Member>
class BaseMenberPair : private Base
{
private:
    Member member;

public:
    BaseMemberPair(const Base &b, const Member &m)
        : Base(b), Member(m)
    {
    }
    const Base &first() const
    {
        return (const Base &)*this;
    }

    Base &first()
    {
        return (Base &)*this;
    }
    const Member &second() const
    {
        return this->Member;
    }

    Member &second()
    {
        return this->Member;
    }
};

#endif // BASE_MENBER_PAIR_H_