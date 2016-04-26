#include <map>
#include <string>
template <class Object, class Key = std::string> class EntityManager
{
	static std::map<Key, Object*> m_map;
public:
	static void Register(Key key, Object * obj);
	Object* Create(const Key& key);
};