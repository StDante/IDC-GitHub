//
//  IDCLection5ObjectHuman.h
//  IDC GitHub
//
//  Created by Alexandr Altukhov on 12.01.16.
//  Copyright © 2016 Alexandr Altukhov. All rights reserved.
//

#ifndef IDCLection5ObjectHuman_h
#define IDCLection5ObjectHuman_h

#define IDCCheckOnNull(value) if (NULL != value) \
{ return NULL; \
}

typedef struct IDCHuman IDCHuman;

extern
IDCHuman *IDCHumanCreateWithName(char *name);

extern
void IDCReleaseHuman(IDCHuman *human);


#endif /* IDCLection5ObjectHuman_h */
