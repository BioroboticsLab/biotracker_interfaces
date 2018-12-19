#pragma once

#include "Interfaces/IModel/IModelTrackedComponent.h"

/**
 * This interface class derives from IModelTrackedComponent.
 * This class is part of the Composite Pattern and represents the the abstract Composite class.
 * Its purpose is to define the responsibility
 * for adding, deleting and returning leaf objects.
 *
 *
 * Its the Plugin Developers full responsibility to choos an internal data structure. This could be e.g. Map, List or Vector.
 */
class BT_INTERFACES_API IModelTrackedTrajectory : public IModelTrackedComponent
{
    Q_OBJECT
    Q_PROPERTY(QList<IModelTrackedComponent*> childNodes READ getChildNodes() WRITE setChildNodes STORED hasChildNodes);
public:
	/**
	 * The constructor.
	 */
	IModelTrackedTrajectory(QObject *parent);

	/**
	 * This methode must be implemented by all derivatives. Its purpose is to provide a mechanism for adding Leaf components to this structure.
	 */
	virtual void add(IModelTrackedComponent *comp, int pos) = 0;

	/**
	* This methode must be implemented by all derivatives. Its functionality shall be a mechanism for removing Leaf components from this structure.
	*/
	virtual bool remove(IModelTrackedComponent *comp) = 0;

	/**
	* This methode must be implemented by all derivatives. Its functionality shall be a mechanism for removing all Leaf components from this structure.
	*/
	virtual void clear() = 0;

	/**
	* This methode must be implemented by all derivatives. Its functionality shall be a mechanism for determining the count/number of children.
	*/
	virtual int size() = 0;

	/**
	 * This should simply return a child object by an index.
	 */
	virtual IModelTrackedComponent* getChild(int index)  = 0;

    virtual IModelTrackedComponent* getValidChild(int index) = 0;

	virtual int validCount() = 0;


	/**
	* This shoudd simply return a last child object (highest index).
	*/
	virtual IModelTrackedComponent *getLastChild() = 0;

	virtual void  setTime(std::chrono::system_clock::time_point t) { _time = t; };
	virtual std::chrono::system_clock::time_point  getTime() { return _time; };

    virtual QList<IModelTrackedComponent*> getChildNodes() = 0;
    virtual void setChildNodes(QList<IModelTrackedComponent*> n) = 0;
    virtual bool hasChildNodes() = 0;

public:
	virtual void operate();

protected:
	static int nextID;
	std::chrono::system_clock::time_point _time;

};
