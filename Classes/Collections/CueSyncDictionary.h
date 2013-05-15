/*
 * Copyright 2013 TheKitchenSync Authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>

/**
 * Interface that CueSyncDictionary shares with NSDictionary
 */
@protocol ICueDictionary <NSFastEnumeration, NSCoding, NSCopying, NSMutableCopying>
@required


#pragma mark - Query

- (NSUInteger)count;

- (NSArray *)allKeys;

- (NSArray *)allValues;

- (id)objectForKey:(id)aKey;

- (id)objectForKeyedSubscript:(id)key;

@end
typedef NSObject<ICueDictionary> CueDictionary;


/**
 * Interface that CueSyncDictionary shares with NSMutableDictionary
 */
@protocol ICueMutableDictionary <ICueDictionary>
@required


#pragma mark - Add

- (void)setObject:(id)anObject forKey:(id<NSCopying>)aKey;

- (void)setObject:(id)object forKeyedSubscript:(id<NSCopying>)aKey;

- (void)addEntriesFromDictionary:(NSDictionary *)otherDictionary;


#pragma mark - Remove

- (void)removeObjectForKey:(id)aKey;

- (void)removeAllObjects;

@end
typedef NSObject<ICueMutableDictionary> CueMutableDictionary;


/**
 * A thread-safe dictionary object composed of
 * an NSMutableDictionary and a lock.
 *
 * Should only be iterated using fast-enumeration. i++ is not synchronized.
 */
@interface CueSyncDictionary : NSObject <ICueMutableDictionary>


#pragma mark - Static Factory

+ (instancetype)from:(NSDictionary *)dictionary;


#pragma mark - Init

- (id)init;

- (id)initWithDictionary:(NSDictionary *)dictionary;


#pragma mark - Dictionary

- (NSMutableDictionary *)unsafeDictionary;

- (NSDictionary *)dictionary;

@end
