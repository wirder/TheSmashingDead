#include "EntityManager.h"
#include <iostream>
#include <iterator>


template <class Object, class Key> std::map<Key, Object*> EntityManager<Object, Key>::m_map = std::map<Key, Object*>();

template <class Object, class Key> void EntityManager<Object, Key>::Register(Key key, Object* obj)
{
	if (m_map.find(key) == m_map.end())
	{
		m_map[key] = obj;
	}
}

template <class Object, class Key> Object* EntityManager<Object, Key>::Create(const Key& key)
{
	Object* tmp = 0;
	typename std::map<Key, Object*>::iterator it = m_map.find(key);
	if (i != m_map.end())
	{
		tmp = ((*it).second)->Clone();
	}
	return tmp;
}

