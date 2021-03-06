//
//  RFWebServiceClientTest+DynamicTest.h
//  ROADWebService
//
//  Copyright (c) 2014 EPAM Systems, Inc. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are met:
//
//  Redistributions of source code must retain the above copyright notice, this
//  list of conditions and the following disclaimer.
//  Redistributions in binary form must reproduce the above copyright notice, this
//  list of conditions and the following disclaimer in the documentation and/or
//  other materials provided with the distribution.
//  Neither the name of the EPAM Systems, Inc.  nor the names of its contributors
//  may be used to endorse or promote products derived from this software without
//  specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
//  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
//  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
//  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
//  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
//  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//  See the NOTICE file and the LICENSE file distributed with this work
//  for additional information regarding copyright ownership and licensing


#import "RFWebServiceClient.h"

#import "RFXMLSerializer.h"
#import "RFSerializableTestObject.h"
#import "RFWebServiceSerializer.h"
#import "RFRequestTestAttribute.h"


@protocol RFWebServiceCancellable;


@interface RFWebServiceClient (DynamicTest)

RF_ATTRIBUTE(RFWebServiceCall, method = @"POST", prototypeClass = [RFSerializableTestObject class])
RF_ATTRIBUTE(RFWebServiceSerializer, serializerClass = [RFXMLSerializer class])
- (id<RFWebServiceCancellable>)testXMLSerializerWithObject:(RFSerializableTestObject *)headerValue withSuccess:(void(^)(id result))successBlock failure:(void(^)(NSError *error))failureBlock;

RF_ATTRIBUTE(RFWebServiceCall, method = @"POST", prototypeClass = [RFSerializableTestObject class], bodyEncoding = NSWindowsCP1251StringEncoding) // NSASCIIStringEncoding
- (id<RFWebServiceCancellable>)testJsonSerializationEncoding:(RFSerializableTestObject *)headerValue withSuccess:(void(^)(id result))successBlock failure:(void(^)(NSError *error))failureBlock;

RF_ATTRIBUTE(RFWebServiceCall, method = @"POST", prototypeClass = [RFSerializableTestObject class], bodyEncoding = NSWindowsCP1251StringEncoding)
RF_ATTRIBUTE(RFWebServiceSerializer, serializerClass = [RFXMLSerializer class])
- (id<RFWebServiceCancellable>)testXMLSerializationEncoding:(RFSerializableTestObject *)headerValue withSuccess:(void(^)(id result))successBlock failure:(void(^)(NSError *error))failureBlock;

RF_ATTRIBUTE(RFWebServiceCall, method = @"GET", relativePath = @"json?%%0%%", prototypeClass = [RFSerializableTestObject class], bodyEncoding = NSWindowsCP1251StringEncoding) // NSASCIIStringEncoding
- (id<RFWebServiceCancellable>)testGetWithJsonSerializationEncoding:(RFSerializableTestObject *)headerValue withSuccess:(void(^)(id result))successBlock failure:(void(^)(NSError *error))failureBlock;

RF_ATTRIBUTE(RFWebServiceCall, method = @"GET", relativePath = @"/test")
RF_ATTRIBUTE(RFRequestTestAttribute, testProperty = @"testString")
- (id<RFWebServiceCancellable>)methodAttributeTestRequest:(void(^)(id result))successBlock failure:(void(^)(NSError *error))failureBlock;

@end
