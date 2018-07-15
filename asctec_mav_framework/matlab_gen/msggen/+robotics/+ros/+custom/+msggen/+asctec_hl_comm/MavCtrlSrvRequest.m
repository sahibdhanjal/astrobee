classdef MavCtrlSrvRequest < robotics.ros.Message
    %MavCtrlSrvRequest MATLAB implementation of asctec_hl_comm/MavCtrlSrvRequest
    %   This class was automatically generated by
    %   robotics.ros.msg.internal.gen.MessageClassGenerator.
    
    %   Copyright 2014-2018 The MathWorks, Inc.
    
    %#ok<*INUSD>
    
    properties (Constant)
        MessageType = 'asctec_hl_comm/MavCtrlSrvRequest' % The ROS message type
    end
    
    properties (Constant, Hidden)
        MD5Checksum = '38a627ff8fcd6d0f534f521aa37786af' % The MD5 Checksum of the message definition
    end
    
    properties (Access = protected)
        JavaMessage % The Java message object
    end
    
    properties (Constant, Access = protected)
        AsctecHlCommMavCtrlClass = robotics.ros.msg.internal.MessageFactory.getClassForType('asctec_hl_comm/mav_ctrl') % Dispatch to MATLAB class for message type asctec_hl_comm/mav_ctrl
    end
    
    properties (Dependent)
        Ctrl
    end
    
    properties (Access = protected)
        Cache = struct('Ctrl', []) % The cache for fast data access
    end
    
    properties (Constant, Hidden)
        PropertyList = {'Ctrl'} % List of non-constant message properties
        ROSPropertyList = {'ctrl'} % List of non-constant ROS message properties
    end
    
    methods
        function obj = MavCtrlSrvRequest(msg)
            %MavCtrlSrvRequest Construct the message object MavCtrlSrvRequest
            import com.mathworks.toolbox.robotics.ros.message.MessageInfo;
            
            % Support default constructor
            if nargin == 0
                obj.JavaMessage = obj.createNewJavaMessage;
                return;
            end
            
            % Construct appropriate empty array
            if isempty(msg)
                obj = obj.empty(0,1);
                return;
            end
            
            % Make scalar construction fast
            if isscalar(msg)
                % Check for correct input class
                if ~MessageInfo.compareTypes(msg(1), obj.MessageType)
                    error(message('robotics:ros:message:NoTypeMatch', obj.MessageType, ...
                        char(MessageInfo.getType(msg(1))) ));
                end
                obj.JavaMessage = msg(1);
                return;
            end
            
            % Check that this is a vector of scalar messages. Since this
            % is an object array, use arrayfun to verify.
            if ~all(arrayfun(@isscalar, msg))
                error(message('robotics:ros:message:MessageArraySizeError'));
            end
            
            % Check that all messages in the array have the correct type
            if ~all(arrayfun(@(x) MessageInfo.compareTypes(x, obj.MessageType), msg))
                error(message('robotics:ros:message:NoTypeMatchArray', obj.MessageType));
            end
            
            % Construct array of objects if necessary
            objType = class(obj);
            for i = 1:length(msg)
                obj(i,1) = feval(objType, msg(i)); %#ok<AGROW>
            end
        end
        
        function ctrl = get.Ctrl(obj)
            %get.Ctrl Get the value for property Ctrl
            if isempty(obj.Cache.Ctrl)
                obj.Cache.Ctrl = feval(obj.AsctecHlCommMavCtrlClass, obj.JavaMessage.getCtrl);
            end
            ctrl = obj.Cache.Ctrl;
        end
        
        function set.Ctrl(obj, ctrl)
            %set.Ctrl Set the value for property Ctrl
            validateattributes(ctrl, {obj.AsctecHlCommMavCtrlClass}, {'nonempty', 'scalar'}, 'MavCtrlSrvRequest', 'Ctrl');
            
            obj.JavaMessage.setCtrl(ctrl.getJavaObject);
            
            % Update cache if necessary
            if ~isempty(obj.Cache.Ctrl)
                obj.Cache.Ctrl.setJavaObject(ctrl.getJavaObject);
            end
        end
    end
    
    methods (Access = protected)
        function resetCache(obj)
            %resetCache Resets any cached properties
            obj.Cache.Ctrl = [];
        end
        
        function cpObj = copyElement(obj)
            %copyElement Implements deep copy behavior for message
            
            % Call default copy method for shallow copy
            cpObj = copyElement@robotics.ros.Message(obj);
            
            % Clear any existing cached properties
            cpObj.resetCache;
            
            % Create a new Java message object
            cpObj.JavaMessage = obj.createNewJavaMessage;
            
            % Recursively copy compound properties
            cpObj.Ctrl = copy(obj.Ctrl);
        end
        
        function reload(obj, strObj)
            %reload Called by loadobj to assign properties
            obj.Ctrl = feval([obj.AsctecHlCommMavCtrlClass '.loadobj'], strObj.Ctrl);
        end
    end
    
    methods (Access = ?robotics.ros.Message)
        function strObj = saveobj(obj)
            %saveobj Implements saving of message to MAT file
            
            % Return an empty element if object array is empty
            if isempty(obj)
                strObj = struct.empty;
                return
            end
            
            strObj.Ctrl = saveobj(obj.Ctrl);
        end
    end
    
    methods (Static, Access = {?matlab.unittest.TestCase, ?robotics.ros.Message})
        function obj = loadobj(strObj)
            %loadobj Implements loading of message from MAT file
            
            % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = robotics.ros.custom.msggen.asctec_hl_comm.MavCtrlSrvRequest.empty(0,1);
                return
            end
            
            % Create an empty message object
            obj = robotics.ros.custom.msggen.asctec_hl_comm.MavCtrlSrvRequest;
            obj.reload(strObj);
        end
    end
end
