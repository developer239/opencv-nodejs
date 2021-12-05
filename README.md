**If you found this library, don't use it in production. It is under heavy development. I don't know what I am doing. With that said this could help you with your pet project if you are on Mac.**

# OpenCV NodeJS

Node bindings for OpenCV. Currently, only tested on Mac.

## Dependencies

In order to make this library work you have to install OpenCV on your machine. I highly recommend to just use `brew`. Otherwise, you can look [here and follow official installation instructions](https://letmegooglethat.com/?q=how+to+install+opencv).

```
brew install opencv
```

All you have to do after that is to install this library with `yarn` or `npm`.

```
yarn add opencv-nodejs
```

## Development

- `yarn build` compiles C++ files
- `yarn test` runs tests

## Types

```typescript
export class Point2 extends Point {
  constructor(point: Point2);
  constructor(x: number, y: number);
  x: number;
  y: number;
  add(point: Point2): Point2;
  subtract(point: Point2): Point2;
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
```