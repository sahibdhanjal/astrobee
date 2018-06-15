classdef Markers < robotics.ros.Message
    %Markers MATLAB implementation of vicon_bridge/Markers
    %   This class was automatically generated by
    %   robotics.ros.msg.internal.gen.MessageClassGenerator.
    
    %   Copyright 2016 The MathWorks, Inc.
    
    %#ok<*INUSD>
    
    properties (Constant)
        MessageType = 'vicon_bridge/Markers' % The ROS message type
    end
    
    properties (Constant, Hidden)
        MD5Checksum = '579f0637989aa8139ce6bf98cf7aabda' % The MD5 Checksum of the message definition
    end
    
    properties (Access = protected)
        JavaMessage % The Java message object
    end
    
    properties (Constant, Access = protected)
        StdMsgsHeaderClass = robotics.ros.msg.internal.MessageFactory.getClassForType('std_msgs/Header') % Dispatch to MATLAB class for message type std_msgs/Header
        ViconBridgeMarkerClass = robotics.ros.msg.internal.MessageFactory.getClassForType('vicon_bridge/Marker') % Dispatch to MATLAB class for message type vicon_bridge/Marker
    end
    
    properties (Dependent)
        Header
        FrameNumber
        Markers_
    end
    
    properties (Access = protected)
        Cache = struct('Header', [], 'Markers_', []) % The cache for fast data access
    end
    
    properties (Constant, Hidden)
        PropertyList = {'FrameNumber', 'Header', 'Markers_'} % List of non-constant message properties
        ROSPropertyList = {'frame_number', 'header', 'markers'} % List of non-constant ROS message properties
    end
    
    methods
        function obj = Markers(msg)
            %Markers Construct the message object Markers
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
        
        function header = get.Header(obj)
            %get.Header Get the value for property Header
            if isempty(obj.Cache.Header)
                obj.Cache.Header = feval(obj.StdMsgsHeaderClass, obj.JavaMessage.getHeader);
            end
            header = obj.Cache.Header;
        end
        
        function set.Header(obj, header)
            %set.Header Set the value for property Header
            validateattributes(header, {obj.StdMsgsHeaderClass}, {'nonempty', 'scalar'}, 'Markers', 'Header');
            
            obj.JavaMessage.setHeader(header.getJavaObject);
            
            % Update cache if necessary
            if ~isempty(obj.Cache.Header)
                obj.Cache.Header.setJavaObject(header.getJavaObject);
            end
        end
        
        function framenumber = get.FrameNumber(obj)
            %get.FrameNumber Get the value for property FrameNumber
            framenumber = typecast(int32(obj.JavaMessage.getFrameNumber), 'uint32');
        end
        
        function set.FrameNumber(obj, framenumber)
            %set.FrameNumber Set the value for property FrameNumber
            validateattributes(framenumber, {'numeric'}, {'nonempty', 'scalar'}, 'Markers', 'FrameNumber');
            
            obj.JavaMessage.setFrameNumber(framenumber);
        end
        
        function markers_ = get.Markers_(obj)
            %get.Markers_ Get the value for property Markers_
            if isempty(obj.Cache.Markers_)
                javaArray = obj.JavaMessage.getMarkers;
                array = obj.readJavaArray(javaArray, obj.ViconBridgeMarkerClass);
                obj.Cache.Markers_ = feval(obj.ViconBridgeMarkerClass, array);
            end
            markers_ = obj.Cache.Markers_;
        end
        
        function set.Markers_(obj, markers_)
            %set.Markers_ Set the value for property Markers_
            if ~isvector(markers_) && isempty(markers_)
                % Allow empty [] input
                markers_ = feval([obj.ViconBridgeMarkerClass '.empty'], 0, 1);
            end
            
            validateattributes(markers_, {obj.ViconBridgeMarkerClass}, {'vector'}, 'Markers', 'Markers_');
            
            javaArray = obj.JavaMessage.getMarkers;
            array = obj.writeJavaArray(markers_, javaArray, obj.ViconBridgeMarkerClass);
            obj.JavaMessage.setMarkers(array);
            
            % Update cache if necessary
            if ~isempty(obj.Cache.Markers_)
                obj.Cache.Markers_ = [];
                obj.Cache.Markers_ = obj.Markers_;
            end
        end
    end
    
    methods (Access = protected)
        function resetCache(obj)
            %resetCache Resets any cached properties
            obj.Cache.Header = [];
            obj.Cache.Markers_ = [];
        end
        
        function cpObj = copyElement(obj)
            %copyElement Implements deep copy behavior for message
            
            % Call default copy method for shallow copy
            cpObj = copyElement@robotics.ros.Message(obj);
            
            % Clear any existing cached properties
            cpObj.resetCache;
            
            % Create a new Java message object
            cpObj.JavaMessage = obj.createNewJavaMessage;
            
            % Iterate over all primitive properties
            cpObj.FrameNumber = obj.FrameNumber;
            
            % Recursively copy compound properties
            cpObj.Header = copy(obj.Header);
            cpObj.Markers_ = copy(obj.Markers_);
        end
        
        function reload(obj, strObj)
            %reload Called by loadobj to assign properties
            obj.FrameNumber = strObj.FrameNumber;
            obj.Header = feval([obj.StdMsgsHeaderClass '.loadobj'], strObj.Header);
            Markers_Cell = arrayfun(@(x) feval([obj.ViconBridgeMarkerClass '.loadobj'], x), strObj.Markers_, 'UniformOutput', false);
            obj.Markers_ = vertcat(Markers_Cell{:});
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
            
            strObj.FrameNumber = obj.FrameNumber;
            strObj.Header = saveobj(obj.Header);
            strObj.Markers_ = arrayfun(@(x) saveobj(x), obj.Markers_);
        end
    end
    
    methods (Static, Access = {?matlab.unittest.TestCase, ?robotics.ros.Message})
        function obj = loadobj(strObj)
            %loadobj Implements loading of message from MAT file
            
            % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = robotics.ros.custom.msggen.vicon_bridge.Markers.empty(0,1);
                return
            end
            
            % Create an empty message object
            obj = robotics.ros.custom.msggen.vicon_bridge.Markers;
            obj.reload(strObj);
        end
    end
end