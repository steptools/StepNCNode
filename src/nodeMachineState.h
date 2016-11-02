//
// Copyright (c) 1991-2016 by STEP Tools Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Author: Samson Bonfante (bonfante@steptools.com)
//

#pragma once
#include <nan.h>
#include <stncapt/MachineState.h>
#include <stncapt/message.h>
#include <uv.h>
class machineState : public Nan::ObjectWrap {
private:
    MachineState * _ms;
    //var ms = new StepNC.machineState(string file);
    static NAN_METHOD(New);
    static inline Nan::Persistent<v8::Function> & constructor() {
        report_via_printf();
	static Nan::Persistent<v8::Function> my_constructor;
	return my_constructor;
    }
    ~machineState() {};
    uv_async_t async;
    uv_thread_t waitqueue;
public:
    void Wait();
    static NAN_MODULE_INIT(Init);

    //Load a machine model from a file.
    //bool LoadMachine(string file);
    static NAN_METHOD(LoadMachine);

	//void WorkingstepTransitionDisableToolMove();
    static NAN_METHOD(WorkingstepTransitionDisableToolMove);

    //void nextWS();
    static NAN_METHOD(NextWS);

    //void PrevWS();
    static NAN_METHOD(PrevWS);

    //int AdvanceState();
    static NAN_METHOD(AdvanceState);

    //int switchWS(int wsid)
    static NAN_METHOD(GoToWS);

    //int GetEIDfromUUID(int uuid);
    static NAN_METHOD(GetEIDfromUUID);

    //String GetGeometryJSON() //Get all Geometry
    //String GetGeometryJSON(string id,string typ) //Get a specific piece of geometry data. types are "NONE" "MESH" and "POLYLINE"
    static NAN_METHOD(GetGeometryJSON);
    //String GetDeltaGeometryJSON(unsigned prev); //Get the geometry associated with the inprocess geometry.
    static NAN_METHOD(GetDeltaGeometryJSON);
    //int GetDeltaGeometryVersion();
    static NAN_METHOD(GetDeltaGeometryVersion);
    //void ResetDeltaGeometry(); //Reset the inprocess geometry.
    static NAN_METHOD(ResetDeltaGeometry);
    //String GetDeltaStateJSON(); //Get changed geometry
    static NAN_METHOD(GetDeltaStateJSON);
    //String GetKeyStateJSON(); //Get All keyframe geometry.
    static NAN_METHOD(GetKeyStateJSON);

    //int GetPrevWSID()
    static NAN_METHOD(GetPrevWSID);

    //int GetWSID()
    static NAN_METHOD(GetWSID);

    //int GetNextWSID
    static NAN_METHOD(GetNextWSID);

    //double GetCurrentFeedrate
    static NAN_METHOD(GetCurrentFeedrate);

    //double GetCurrentFeedrate
    static NAN_METHOD(GetCurrentSpindleSpeed);

    // void SetToolPosition
    static NAN_METHOD(SetToolPosition);
};


