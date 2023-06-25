#include "Scene.h"

void Scene::RemoveElement(unsigned int element) {
	for (unsigned int i = element; i < numObjects; i++) {
		objects[i] = objects[i + 1];
	}
}

Scene::Scene(unsigned int maxObjects) : maxObjects(maxObjects) {
	objects = new Object3D*[maxObjects];
}

Scene::~Scene() {
	delete[] objects;
}

bool Scene::UseEffect() {
	return doesUseEffect;
}

void Scene::EnableEffect() {
	doesUseEffect = true;
}

void Scene::DisableEffect() {
	doesUseEffect = false;
}

Effect* Scene::GetEffect() {
	return effect;
}

void Scene::SetEffect(Effect* effect) {
	this->effect = effect;
}

void Scene::AddObject(Object3D* object) {
	objects[numObjects] = object;

	numObjects++;
}

void Scene::RemoveObject(unsigned int i) {
	if (i <= numObjects && i > 0) {
		RemoveElement(i);

		numObjects--;
	}
}

void Scene::RemoveObject(Object3D* object) {
	// check if pointers are equal for all objects, if so delete and shift array
	for (unsigned int i = 0; i < numObjects; i++) {
		if (objects[i] == object) {
			RemoveElement(i);
			break;
		}
	}
}

Object3D** Scene::GetObjects() {
	return objects;
}

uint8_t Scene::GetObjectCount() {
	return numObjects;
}
