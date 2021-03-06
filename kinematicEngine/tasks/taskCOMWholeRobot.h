/*
 *  Created on: 28.02.2014
 *      Author: lutz
 */

#ifndef KINEMATICENGINETASKCOMWHOLEROBOT_H_
#define KINEMATICENGINETASKCOMWHOLEROBOT_H_

#include "task.h"

namespace kinematicEngine {

class TaskCOMWholeRobot : public Task {
	typedef kinematics::NodeID NodeID;
public:

	typedef int SubDimension;

	TaskCOMWholeRobot();

	TaskCOMWholeRobot(std::string name, NodeID base, KinematicTree const &tree);

	TaskCOMWholeRobot(std::string name, NodeID base, NodeID reference, KinematicTree const &tree);

	virtual ~TaskCOMWholeRobot();

	virtual arma::colvec getError(const KinematicTree &kinematicTree) const;

	/**
	 * get the jacobian for this task
	 *
	 * @param kinematicTree
	 * @param normalizeJacobian
	 *
	 * @return
	 */
	virtual arma::mat getJacobianForTask(const KinematicTree &kinematicTree, arma::mat &jacobianWithoutRemovedDOFs, bool normJacobian = false) const;

private:
	NodeID m_referenceCoordinateSystem;

	arma::mat getJacobianForTaskSub(const KinematicTree &kinematicTree,
			const KinematicNode *node,
			bool traversingUp,
			KinematicMass &o_massFromSubTree) const;
};

}

#endif /* KINEMATICENGINETASKCOMWHOLEROBOT_H_ */
