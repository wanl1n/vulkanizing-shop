#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "ObjectGroup.h"
#include "Assets/Texture.hpp"
#include "From-GDGRAP2/GameObject.h"

/**
 * \brief Similar to the game object manager, this class stores model instances
 */
class ModelManager
{
public:
	typedef glm::vec3 vec3;
	typedef std::string String;
	typedef std::vector<std::shared_ptr<GameObject>> List;
	typedef std::unordered_map<String, std::shared_ptr<GameObject>> HashTable;

	typedef std::vector<std::shared_ptr<ObjectGroup>> ObjectGroupList;

	typedef std::vector<Assets::Model> ModelList;

	static ModelManager* getInstance();
	static void initialize();
	static void destroy();

	std::shared_ptr<GameObject> findObjectByName(String name);
	List getAllObjects() const;
	
	int activeObjects() const;
	std::shared_ptr<GameObject> getLastObject();
	void addObject(std::shared_ptr<GameObject> gameObject);
	void addObject(std::shared_ptr<ObjectGroup> objectGroup);
	void createObject(GameObject::PrimitiveType type);
	void createObjectFromFile(String name, GameObject::PrimitiveType type, vec3 position, vec3 rotation, vec3 scale);
	void deleteObject(std::shared_ptr<GameObject> gameObject);
	void deleteObjectByName(String name);
	void setSelectedObject(String name);
	void setSelectedObject(std::shared_ptr<GameObject> gameObject);
	std::shared_ptr<GameObject> getSelectedObject();

	void clearAllObjects();

	ModelList getAllObjectModels() const;

private:
	ModelManager() = default;
	~ModelManager() = default;
	ModelManager(ModelManager const&) {};             // copy constructor is private
	ModelManager& operator=(ModelManager const&) {};  // assignment operator is private*/
	static ModelManager* sharedInstance;

	HashTable gameObjectMap;
	List gameObjectList;
	ObjectGroupList objectGroupList;

	std::shared_ptr<GameObject> selectedObject = nullptr;
};

