/**
 * Licensed to Green Energy Corp (www.greenenergycorp.com) under one or
 * more contributor license agreements. See the NOTICE file distributed
 * with this work for additional information regarding copyright ownership.
 * Green Energy Corp licenses this file to you under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except in
 * compliance with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * This project was forked on 01/01/2013 by Automatak, LLC and modifications
 * may have been made to this file. Automatak, LLC licenses these modifications
 * to you under the terms of the License.
 */
#ifndef SECAUTH_PERMISSIONS_H
#define SECAUTH_PERMISSIONS_H

#include <opendnp3/gen/FunctionCode.h>

namespace secauth
{

/**
*	Describes what function codes a user is authorized to perform
*/
class Permissions
{	
	// helper class to force explicit initialization
	struct Permission
	{		
		Permission(bool allowed_) : allowed(allowed_) {}

		bool allowed;

		private:

		Permission() = delete;
	};

public:

	Permissions() : Permissions(false)
	{}
	
	static Permissions AllowNothing();
	static Permissions AllowAll();
	
	void Allow(opendnp3::FunctionCode code);
	void Deny(opendnp3::FunctionCode code);

	bool IsAllowed(opendnp3::FunctionCode) const;

private:

	Permission* GetPermission(opendnp3::FunctionCode code);

	Permission confirm;
	Permission read;
	Permission write;
	Permission select;
	Permission operate;
	Permission directOperate;
	Permission directOperateNR;
	Permission immediateFreeze;
	Permission immediateFreezeNR;
	Permission freezeClear;
	Permission freezeClearNR;
	Permission freezeAtTime;
	Permission freezeAtTimeNR;
	Permission coldRestart;
	Permission warmRestart;
	Permission initializeData;
	Permission initializeApplication;
	Permission startApplication;
	Permission stopApplication;
	Permission saveConfiguration;
	Permission enableUnsolicited;
	Permission disableUnsolicited;
	Permission assignClass;
	Permission delayMeasure;
	Permission recordCurrentTime;
	Permission openFile;
	Permission closeFile;
	Permission deleteFile;
	Permission getFileInfo;
	Permission authenticateFile;
	Permission abortFile;
		
	Permissions(bool allowByDefault);

};

}

#endif

