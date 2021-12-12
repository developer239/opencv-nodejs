declare class Point {
}

export class Point2 extends Point {
  constructor(point: Point2);
  constructor(x: number, y: number);

  x: number
  y: number

  add(point: Point2): Point2;

  subtract(point: Point2): Point2;
}

export class Size {
  constructor();
  constructor(width: number, height: number);

  width: number
  height: number
}

export class Rect {
  constructor();
  constructor(x: number, y: number, width: number, height: number);

  x: number
  y: number
  width: number
  height: number

  rescale(scale: number): void;

  toSquare(): void;
}

declare class Vec {
}

export class Vec2 extends Vec {
  constructor(x: number, y: number);

  x: number
  y: number
}

export class Vec3 extends Vec {
  constructor(x: number, y: number, z: number);

  x: number
  y: number
  z: number
}

export class Vec4 extends Vec {
  constructor(x: number, y: number, z: number, w: number);

  x: number
  y: number
  z: number
  w: number
}

export class RotatedRect {
  constructor(
    center: Point2,
    size: Size,
    angle: number
  );

  center: Point2
  size: Size
  angle: number
}

export class Mat {
  constructor();
}

export function imRead(path: string): Promise<Mat>;
export function imShow(): void;
export function waitKey(delay?: number): void;
