export class Point {
  constructor(point: Point);
  constructor(x: number, y: number);
  x: number;
  y: number;
  add(point: Point): Point;
  subtract(point: Point): Point;
}

export class Size {
  constructor();
  constructor(width: number, height: number);
  width: number;
  height: number;
}

export class Rect {
  constructor();
  constructor(x : number , y : number , width : number , height : number);
  x: number;
  y: number;
  width: number;
  height: number;
  rescale(scale: number): void;
  toSquare(): void;
}

export class Vec {}

export class Vec2 extends Vec {
  constructor(x: number, y: number);
  x: number;
  y: number;
}

export class Vec3 extends Vec {
  constructor(x: number, y: number, z: number);
  x: number;
  y: number;
  z: number;
}

export class Vec4 extends Vec {
  constructor(x: number, y: number, z: number, w: number);
  x: number;
  y: number;
  z: number;
  w: number;
}
